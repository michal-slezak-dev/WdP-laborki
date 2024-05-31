#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct point 
{
    int point_no;
    char point_name[11]; // 10 znaków, ale jeszcze jeden na \0
    float x;
    float y;
} Point;

float random_float_num_gen(int left, int right);
int num_of_structures(FILE *file);
void display_file_content(FILE *file, int struct_num);
void mem_alloc_err(Point* arr);

int main()
{
    srand(time(NULL));
    
    // for(int i = 0; i < 50; i++)
    // {
    //     printf("%f\n", random_float_num_gen(-50, 50));
    // }
    int n = 0;
    printf("Podaj liczbe struktur-punktow do wpisania: ");
    scanf("%d", &n);

    FILE *file;
    Point* points = (Point*)calloc(n, sizeof(Point));
    mem_alloc_err(points);
    
    for(int i = 0; i < n; i++)
    {
        // printf("Podaj numer %d. punktu: ", i + 1);
        printf("Podaj numer punktu: ");
        scanf("%d", &points[i].point_no);

        getchar(); // bo newline mi kiepści potem fgetsa ;-(
        // printf("Podaj nazwe %d. punktu (10 znakow max.): ", i + 1);
        printf("Podaj nazwe punktu (10 znakow max.): ");
        fgets(points[i].point_name, 11, stdin); // czyta maxlen-1 albo do \n ze streama to 11 to define moznaxbylo tez dac i na 11 znak daje \0 fgets

        points[i].x = random_float_num_gen(-50, 50);
        points[i].y =  random_float_num_gen(-50, 50);

    }

    file = fopen("SeriaX4.bin", "wb"); // dla ab też działa, sprawdzałem
    if(file) // jeśli poprawnie otworzono
    {
        fwrite(points, sizeof(Point), n, file);
        fclose(file); // zamykam plik po zapisie
    }else
    {   
        free(points);
        points = NULL;

        fprintf(stderr, "Nie udalo sie otworzyc pliku SeriaX4.bin ;-(");
        return 1;
    }
    
    int struct_num = num_of_structures(file);
    if(struct_num != -1)
    {
        printf("\nLiczba zapisanych w pliku struktur-punktow: %d\n\nTe punkty to:\n", struct_num);
        display_file_content(file, struct_num); // otwarcie pliku do odczytu i wypisanie zawartosci
    }else
    {
        fprintf(stderr, "Nie udalo sie otworzyc pliku SeriaX4.bin ;-(");
        return 1; // wtedy blad jakis z odczytem pliku
    }
    // if(struct_num != -1)
    // {
    //  printf("Liczba zapisanych w pliku struktur-punnktow: %d\n", struct_num);
    // }

    free(points); // na sam koniec zwalniam pamięć
    points = NULL;

    return 0;
}

float random_float_num_gen(int left, int right)
{
    float random_num = left + (rand() / ((float) RAND_MAX)) * (right - left);
    return random_num;
}

int num_of_structures(FILE *file)
{
    file = fopen("SeriaX4.bin", "rb");
    if(!file) // nie udalo sie otworzyc pliku
    {
        return -1; // -1,bo teoretycznie moze byc 0 lub 1 struktura
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    // fseek(file, 0, SEEK_SET);
    fclose(file);

    int num = file_size / sizeof(Point);

    return num;
}

void display_file_content(FILE *file, int struct_num) // mozna teoretycznie oryginal tablicy przekazac, ale po co w sumie
{
    Point point; // i tak w pętli będziemy odczytywac, więc po co na tablicy działać
    file = fopen("SeriaX4.bin", "rb");
    if(file) // void nie powinien zwracać niczego, wiec lepiej obsłużyć przeciwne zdarzenie, jesli otwarto poprawnie plik
    {
        for(int i = 0; i < struct_num; i++)
        {
            // fread zwroci 0 jesli juz nic nie ma
            if(fread(&point, sizeof(Point), 1, file))
            {
                printf("Numer punktu: %d\n", point.point_no);
                printf("Nazwa punktu: %s", point.point_name);

                // jesli krotsze nazwy wpisane niz 10 znakow to na indeksie tym nie bedzie newline strlen nie zwraca mi z nulloperatorem dlugosci
                if(point.point_name[strlen(point.point_name) - 1] != '\n') // fgets dodaje \0 na koniec ? po wczytaniu maxlen-1 lub jak newline spotka od razu po nim
                {
                    printf("\n");
                }

                printf("Wspolrzedna X punktu: %f\n", point.x);
                printf("Wspolrzedna Y punktu: %f\n", point.y);
            }
            printf("\n");
        }
    }
    fclose(file);
}

void mem_alloc_err(Point* arr)
{
    if(arr == NULL)
    {
        printf("Nie udalo sie zaalokowac pamieci :-(");
        exit(1);
    }
}