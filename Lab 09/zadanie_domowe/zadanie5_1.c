#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_num_gen(int n);
// int file_err(FILE *file, const char *file_name);
void display_file_content(FILE *file, const char *file_name, int *n); // na oryginale n moge pracować wsm, można też dać bez * i na kopii pracować w sumie

int main()
{
    srand(time(NULL));

    FILE *file, *file_positive, *file_negative;

    file = fopen("dane1.txt", "w");
    if(!file) // jeśli coś poszło nie tak, moznaby to wsm do funkcji dać
    {
        return 1;
    }

    int n = 0;
    printf("Podaj liczbe liczb calkowitych z zakresu [-50;49] do wylosowania: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        fprintf(file, "%d ", random_num_gen(n));
    }

    fclose(file);

    file = fopen("dane1.txt", "r");
    if(!file) // coś poszło nie tak z otwarciem pliku
    {
        return 1;
    }
    
    // tworze 2 pliki tekstowe na "wyłuskiwanie" liczb dodatnich i ujemnych z pliku dane1.txt
    file_positive = fopen("dodatnie.txt", "w+");
    file_negative = fopen("ujemne.txt", "w+");

    if(!file_positive) // coś poszło nie tak
    {
        return 1;
    }

    if(!file_negative) // coś poszło nie tak
    {
        return 1;
    }

    // pobieram wartości z dane1.txt nie używając n i odpowiednio dadatnie liczby dodaje do dodatnie.txt a ujemne do ujemne.txt
    while(fscanf(file, "%d", &n) != EOF) // n i tak już nie używam, bo nie moge, wiec sprawdzam czy nie doszedłem do końca pliku
    {   
        if(n == 0)
        {
            continue;
        }else if(n > 0)
        {
            fprintf(file_positive, "%d ", n);
        }else
        {
            fprintf(file_negative, "%d ", n);
        }
    }

    // wracam na początek plików, żeby znowu się w otwieranie nie bawić ;-)
    fseek(file, 0, SEEK_SET);
    fseek(file_positive, 0, SEEK_SET);
    fseek(file_negative, 0, SEEK_SET);

    display_file_content(file, "dane1.txt", &n);
    display_file_content(file_positive, "dodatnie.txt", &n);
    display_file_content(file_negative, "ujemne.txt", &n);

    // printf("Zawartosc pliku dane1.txt:\n");
    // while(fscanf(file, "%d", &n) != EOF)
    // {
    //     printf("%d ", n);
    // }

    // printf("\n\nZawartosc pliku dodatnie.txt:\n");
    // while(fscanf(file_positive, "%d", &n) != EOF)
    // {
    //     printf("%d ", n);
    // }

    // printf("\n\nZawartosc pliku ujemne.txt:\n");
    // while(fscanf(file_negative, "%d", &n) != EOF)
    // {
    //     printf("%d ", n);
    // }

    fclose(file);
    fclose(file_positive);
    fclose(file_negative);

    return 0;
}

int random_num_gen(int n)
{
    int random_num = (rand() % 100 - 50); // [-50;49]

    return random_num;
}

void display_file_content(FILE *file, const char *file_name, int *n)
{
    printf("Zawartosc pliku %s:\n", file_name);
    while(fscanf(file, "%d", n) != EOF)
    {
        printf("%d ", *n);
    }
    printf("\n");
}

// int file_err(FILE *file, const char *file_name)
// {
//     if(!file) // coś nie tak poszło podczas otwierania pliku fopen()
//     {   
//         printf("Cos poszlo nie tak z otwieraniem pliku %s ;-(", file_name);
//     }
//     return 1;
// }

