//struktura do przechowywania punktu na plaszczyznie, napisz funkcje, ktora sprawdzi w ktorej cwiartce dany punkt sie znajduje
// od użytkownika i tablica struktur
// n - jak duza tablica, wziac punkty losowe, funkcja wypisywala w ktorej cwiartce, pojedynczy punkt
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct punkt {
    int x;
    int y;
};

int cwiartka(struct punkt pkt)
{
    //1
    if(pkt.x > 0 && pkt.y > 0)
        return 1;
    //2
    if(pkt.x < 0 && pkt.y > 0) // else ify tez mozna
        return 2;
    //3
    if(pkt.x < 0 && pkt.y < 0)
        return 3;
    //4
    if(pkt.x > 0 && pkt.y < 0) 
        return 4; // tutj zeby bardzieje elegancko bylo to mozna tez else dac 
    // jak zero to dac ze w zadnej cwiartce
    return 0; // else dac mozna zeby bardziej elegancko 
}

int main()
{
    srand(time(NULL));
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);

    struct punkt *punkty = (struct punkt*)calloc(n, sizeof(struct punkt));
    for(int i = 0; i < n; i++){
        (punkty + i)->x = (rand() % (b - a + 1)) + a;
        punkty[i].y = (rand() % (b - a + 1)) + a;
    }

    for(int i = 0; i < n; i++)
        printf("x=%d, y=%d, %d\n",punkty[i].x, punkty[i].y, cwiartka(punkty[i]));


    free(punkty);
    return 0;
}