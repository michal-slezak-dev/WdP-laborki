#include <stdio.h>
#include <stdlib.h>

typedef struct Osoba{
    char imienazwisko[20];
    int wiek;
} Element;

typedef struct elementlisty{
    Element dane;
    struct elementlisty *wsk;
} T_lista;

int main()
{

    T_lista *head = NULL;

    return 0;
}