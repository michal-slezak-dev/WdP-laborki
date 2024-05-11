#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int losowanie(int a, int b)
{
	int wylosowana = (rand() % (b - a + 1)) + a; // % b - ato by bylo tylko od 0 do 9 dla np b = 10 na koñcu + a, ¿eby nie od 0 tylko od a sie zaczynalo
	return wylosowana;
}

int main(){
    srand(time(NULL)) ;
    //*tab = 8;
    // tab++ -> straci³em tablicê, straci³em pierwszy element, nazwa tablicy jest sta³¹ na 1. el. tablicy
    //*(tab + 1) = 8; mo¿na tak ju¿
    // z px pewniejsze
    // dla dwuwymiarowych to nazwa tablicy to wskaŸnik na pierwszy wiersz, bo u³o¿one s¹ te¿ obok siebie

    int tab[10] = {0}; // losowe wartoœci od a do b u¿ywaj¹c wskaŸników
    int a = 0, b = 0;

    while(1){
        printf("Podaj liczby a i b jako krance przedzialu: ");
        fflush(stdin);
        scanf("%d %d", &a, &b); // takiego raczej nie powinno siê stosowaæ najlepiej sklejone %d%d bo moge wtedy 5 8 lub 5 enter 8 itd.
        if(a <= b)
            break;
    }

    int *px = tab;

    for(int i = 0; i < 10; i++){
        //*(px + i) = losowanie(a, b);
        //lub
        //*px = losowanie(a, b);
        //px++;
        // lub
        *(tab + i) = losowanie(a, b);
    }

    //px = tab; // bo wtedy na koñcu poprzedniej pêtli i jestem o jeden znak poza tablic¹
    printf("\n");
    for(int i = 0; i < 10; i++){
        printf("Indeks: %d, wartosc: %d\n", i, *(px + i));
    }

    return 0;
}

