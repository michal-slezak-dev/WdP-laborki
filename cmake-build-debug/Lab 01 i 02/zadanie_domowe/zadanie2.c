#include <stdio.h>

int main(void)
{
    // tak jak w szablonie deklaracja zmiennych
    int *ip, a;

    // wskazanie zmienną ip na zmienną a
    // ustawienie wartości zmiennej a na 10 używając wskaźnika ip
    ip = &a;
    *ip = 10;

    //output
    printf("Zawartość ip: %d\nZawartosc a: %d\nAdres zmiennej a: %p\nRozmiar w pamięci operacyjnej jaki zajmuje adres zmiennej a: %d", *ip, a, &a, sizeof(&a));

    return 0;
}