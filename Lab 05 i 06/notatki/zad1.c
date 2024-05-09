#include <stdio.h>
#include <stdlib.h>

struct Osoba{
    char imie[10];
    char nazwisko[20];
    int wiek;
};

typedef struct Element_listy{
    struct Osoba dane;
    struct Element_listy* next;
} ListaJ;
//wstawianie na poczatek, lifo
ListaJ* AddHead(ListaJ *head, struct Osoba d) // to head to adres calej struktury, dane to tez struct cala osoba
{// head przekazuje jako wartosc adresu nwoa, wiec ja potrzebuje adresu heada a nie wartosci adresu nowej, wiec jeszcze jedna gwiazdka
// musze zwroci nowego heada, a head to ListaJ ma typ, przekazywalismy zawartosc heada a nie jego adres dlatego voida nie mozna
    //listy wstawiajace lepiej pisac wedle schematu
    // 1. alokacja pamieci na nowo komorke, bo nowa komorke wstawic chce, wiec musze pamiec zaalokowac 2.wypelnienie wszystich danych imien azwisko wiek, adres 3. znalezienie miejsca i dolaczenie do struktury

    // 1. Alokacja 
    ListaJ *nowa; // nowa komorkwa
    nowa = (ListaJ*)malloc(sizeof(ListaJ)); // 1 * sizeof, bo 1 komorke chce, nowa komorka, nowa struktura lokalna
    // i jako wskaznik dam na heada a head powinienm wskazywac na nowa, wiec heada trzeba rpzesunac, zeby znowu na poczatek listy przechowywal
    
    //2. przypisanie danych, wypelnianie nowa
    nowa->dane = d; // nowa to wskaznik
    nowa->next = head; // mamy tu pozostala czesc listy, kolejne elementy

    // 3. dolaczenie
    head = nowa; // przesuwam head na nowa, cofam w lewo o 1, adres przesuwam

    return head;
}

void wypisz(ListaJ *head){ // dzialamy dopoki nulla na koncu napotkamy, czyli koniec listy , 
    ListaJ *tmp = head; // mozna head tylko, bo dzialam na kopii i tak

    while(tmp != NULL)
    {
        printf("%s %s %d\n", tmp->dane.imie, tmp->dane.nazwisko, tmp->dane.wiek);
        tmp = tmp->next;
    }

}
// te co nie modyfikuja to zalezy co to za funkcja
ListaJ* zwolnij(ListaJ *head) // zaracamy swieza wyczyszczona glowe, wszelkie funkcje modyfikujace liste, powinny zwrocic nowa glowe, korzen itd.
{//dzialam na kopii
    ListaJ *tmp = head;
    while(head) // dopoki lista istnieje
    {
        tmp = head->next; // zapamietac gdzie dalsza czesc listy
        free(head);
        head = tmp;
    }

    return head;
}

// funkcja rekurencyjna obliczajaca dlugosc listy
int dlugosc_listy(ListaJ* head)
{
    if(head == NULL)
    {
        return 0; // jak koniec listy
    }else{
        return 1 + dlugosc_listy(head->next); // 1 + dlugosc kolejnej czesci listy next
    }
}

int main() // na poczatek listy wstawia, struktura tak jak na podanych wczesniej slajdach
{
    // head = NULL trzeba, zeby smieci nie bylo
    ListaJ *head = NULL;
    struct Osoba o1;

    // komunikacja z uzytkownikiem
    int n = 0;
    printf("Podaj n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Podaj imie");
        scanf("%s", o1.imie);
        // puts("");
        printf("Podaj nazwisko");
        scanf("%s", o1.nazwisko);
        // puts("");
        printf("Podaj wiek");
        scanf("%d", &o1.wiek); // pobiera to pierweszego znaku bialowego, wiwc wywala go na wejscie, dlatego newline'a dostejym
        // jesli po scanf gets to gets wczytuje entera wtedy bufor trzeba czyscic, przy fgets tez
        //wtedy fflush(stdin) lub getchar przed getsem jesli wczesniej scanf byl
        head = AddHead(head, o1);
    }

    
    wypisz(head);
    printf("\n\nDlugosc:%d", dlugosc_listy(head));

    head = zwolnij(head); // zeruje heada
    head = NULL;

    return 0;
}