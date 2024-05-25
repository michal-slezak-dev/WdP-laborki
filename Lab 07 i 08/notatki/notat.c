#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement
{
    int data;
    struct ListElement* next;
    struct ListElement* prev;
} LinkedList; // też deklaruje wskaźnik do tej struktury, mozna ale nie trzeba LinkedList, *ptr

void addHead(LinkedList **head, LinkedList **tail, int key); // chcemy zwrócić heada i taila, wiec oryginaly a nie kopie
void deleteList(LinkedList **head, LinkedList **tail);
void displayList(LinkedList *tail);

int main()
{
    // srand(time(NULL));
    int n = 0, d = 0;
    LinkedList* head = NULL; // lub LinkedList* head; wsk head;
    LinkedList* tail = NULL; // LinkedList* head, *tail; head = tail = NULL

    printf("Podaj liczbe elementow: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        d = rand()%10;
        //scanf("%d", &d);
        addHead(&head, &tail, d);
    }

    displayList(tail);

    deleteList(&head, &tail);

    return 0;
}

void addHead(LinkedList **head, LinkedList **tail, int key) // napewno powinna zwrócić głowe i ogon!!!, adres adresu, czyli oryginał a nie kopie
{
    // 1. Alokacja pamięci
    LinkedList *new = (LinkedList*)malloc(sizeof(LinkedList)); // nowa komórka listy, wlascicwie to wskaznik do niej
    //calloc raczej do tablic, zeby wyzerowana tablica byla

    // 2. Zapisanie danych
    new->data = key;
    new->next = new->prev = NULL; // head = tail, gdy lista jest pusta

    new->next = *head; // jesli head = null to bede mial to co w 47. a nie 31. linijsce

    if(*head != NULL) // jesli head istnieje to prev z heada na new wskazywac musi
    {
        (*head)->prev = new;
        // // 3. Dołączenie
        // head = new; // nowa głowa, wskazuje na zawartosc jako new
    }else // jeśli lista pusta to wtedy ten nowy element headem jest i tailem jednoczesnie
    {
        // *head = *tail = new;
        *tail = new; // bo sie powatarza *head = new to mozna dac po ifie 
    }

        // 3. Dołączenie
        *head = new; // nowa głowa, wskazuje na zawartosc jako new

}

void deleteList(LinkedList **head, LinkedList **tail)
{
    LinkedList* tmp = *head;
    // LinkedList* tmp2 = *tail;
    while(*head)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;

    // lub na to samo wychodzi
        // tmp = *head;
        // *head = (*head)->next;
        // free(tmp);
    }

    *head = *tail = NULL; // moge tylko taila wynulowac, bo petla dopoki head nie jest nullem
}

void displayList(LinkedList *tail) // jeśli funkcja zmienia liste to podwójny wskaźnik, jeśli nie to pojedynczy
{
    if(tail != NULL) // rekurencja początkowa, bo najpierw rekurencja potem działanie
    {
        displayList(tail->prev);
        printf("Klucz: %d\n", tail->data);
    }

    // lub 
    // if(head != NULL)
    // {
    //     printf("Klucz: %d\n", head->data);
    //     displayList(head->next);
    // }

    // noramlnie warunek końcowy return, ale to niedobra praktyka, wiec lepiej dac warunek, w ktorym robimy cos i nie marrtwic sie o warunek koncowy
}