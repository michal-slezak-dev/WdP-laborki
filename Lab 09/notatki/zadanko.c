#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    
    srand(time(NULL));

    FILE *plik = fopen("plik.txt", "r+"); // tylko tu plik.txt z w na a
    if(!plik)
    {   
        printf("Nie ma pliku");
        return 1;
    }

    int n = 0;
    printf("Podaj liczbe liczb do wylosowania: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        // cyferka po cyferce, musze miec separator tabl, newline, spacja, przecinek nie bo to char
        fprintf(plik, "%d ", rand()%100 - 100);
    }

    fclose(plik);

    // min max suma srednia, licznik
    // mozna ustawic poczatkowo na piewsza wartosc w pliku bo automatycznie przesuwa sie

    int suma, min, max, licznik;
    float srednia;

    plik = fopen("plik.txt", "r");
    //zabezpieczenie plik == NULL
    fscanf(plik, "%d", &n); // pobiera wartosci chyba ze na koniec pliku napotka, automatycznie sie w prawo przesuwa na kolejna pozycje
    suma = min = max = n;
    licznik = 1;

    while(fscanf(plik, "%d", &n) != EOF) // dopoki scanf pobiera jakakolwiek wartosc, mam pobierac
    {
        if(n > max)
        {
            max = n;
        }

        if(n < min)
        {
            min = n;
        }

        suma += n;
        licznik++;
    }

    fclose(plik);

    srednia = (float) suma / licznik; // zle bo dzielenie intow, wystarczy, ze jedna jest floatem i mamy floatowe dzielenie
    fprintf(stdout,"min %d max %d suma %d srednia %f, licznik %d", min, max, suma, srednia, licznik); // tak tez mozna jak damy stdout
    printf("\nmin %d max %d suma %d srednia %.3f licznik %d", min, max, suma, srednia, licznik);

    return 0;
}