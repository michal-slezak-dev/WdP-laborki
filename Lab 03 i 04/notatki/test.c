#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int szukaj(int tab[], int n, int target){ // arg to tablica
    for(int i = 0; i < n; i++)
    {
        if(tab[i] == target)
            return 1;
    }
    return 0;
}

//n a b, zwraca pointer do tablicy
int* gen(int n, int a, int b) // funkcja szukaj czy  jest w tablicy czy nie 
{
    int* tab = (int*)calloc(n, sizeof(int)); // calloc bo zeruje
    // TO DO: zrobić to, żeby duplikatów nie było, zeby losowalo w funkcji szukaj
    int i = 0;
    while(i < n)
    {
        int los = (rand() % (b - a + 1)) + a;
        if(szukaj(tab, n, los) == 0)
        {
            tab[i] = los;
        }else
        {
            los = (rand() % (b - a + 1)) + a;
        }
        i++;
    }

    return tab;
}

int main()
{   
    srand(time(NULL));
    // napisz funkcje, ktora wygeneruje n elementowa liczb losowych od a do b
    int n = 0, a = 0, b = 0; // b - a + 1 > n musi byc

    scanf("%d", &n);
    scanf("%d%d", &a, &b);

    int* t = gen(n, a, b); // bo funkcja zwraca zmienna wskaznikowa co innego argument wywołania i paramentr funkcji

    for(int i = 0; i < n; i++){
        printf("%d\n", *(t+i));

    }

    free(t); // pamiętać!!!! zawsze zwlniamy jak zaalokujemyu 

    return 0;
}//napisac 2 funkcje, losowe wartosci od a do b, ale zeby elementy sie nie powtarzaly

//puts("")  wstawia tez newline z automatu
// tego typu zadanie na kolokwium
// flagą też można tak jak chciałem