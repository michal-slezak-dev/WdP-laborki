#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//n a b, zwraca pointer do tablicy
int* gen(int n, int a, int b)
{   //NIE WOLNO tab[100], bo zwracam wartość a nie wskaźnik, uważać!!!
    int* tab = (int*)calloc(n, sizeof(int)); // calloc bo zeruje
    for(int i = 0; i < n; i++)
        *(tab + i) = (rand() % (b - a + 1)) + a; // spr jak dziala dokladnie mozna tez tab[i] bo to tablica juz

    // free tu nie mozna, bo zwolnie pamiec, ktora chce zaalokowac, za wczesnie xD
    return tab;
}

int main()
{   
    srand(time(NULL));
    // napisz funkcje, ktora wygeneruje n elementowa liczb losowych od a do b
    int n = 0, a = 0, b = 0;

    scanf("%d", &n);
    scanf("%d%d", &a, &b);

    int* t = gen(n, a, b); // bo funkcja zwraca zmienna wskaznikowa co innego argument wywołania i paramentr funkcji

    for(int i = 0; i < n; i++){
        printf("%d\n", *(t+i));

    }

    free(t); // pamiętać!!!! zawsze zwlniamy jak zaalokujemyu 

    return 0;
}