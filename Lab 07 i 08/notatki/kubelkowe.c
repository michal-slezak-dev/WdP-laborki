#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* tabl = (int*)calloc(10, sizeof(int));
    int n = 10;
    for(int i = 0; i < n; i++)
    {
        tabl[i] = rand()%20;
    }
    
    int min = tabl[0], max = tabl[0];

    for(int i = 0; i < n; i++) // TO DO: napisać funkcje zwracajaca jednoczesnie min i max to ze wskaznikami
    {
        if(tabl[i] < min)
        {
            min = tabl[i];
        }

        if(tabl[i] > max)
        {
            max = tabl[i];
        }
    }

    for(int i = 0; i < n; i++)
        printf("%d ", tabl[i]);

    int rozmiar_kubelki = max - min + 1;

    int* kubelki = (int*)calloc(rozmiar_kubelki, sizeof(int)); // oczywiscie to w unkcji najepiej int tab[]

    for(int i = 0; i < n; i++) // lub i < n i - min bo chce w indeks zerowy trafic kubelka
    {   
        // if(i < n)
        kubelki[tabl[i] - min]++; // i < n bo pod zerowym indeksem jest min wystpapienia, bo inaczej zakres tabliy wyczerpie
    }

    printf("\n");
    for(int i = 0; i < rozmiar_kubelki; i++)
        printf("%d ", kubelki[i]);

    printf("\n");
    for(int i = 0; i < rozmiar_kubelki; i++) 
    {
        while(kubelki[i] != 0) // mozna forem, ale licznik wtedy = 0 i 
        {
            printf("%d ", i); // tab[licznik++] = i + min, bo pod zerowym indeksem bede mial min wystapienia
            kubelki[i]--;
        }
    }



    free(tabl);
    free(kubelki);
    tabl = NULL; // tutaj w tej funkcji mozna zwolnic ja pamiec, bo i tak na wartosciach dzialamy w talblicy oryginalow
    kubelki = NULL;

    return 0;
}