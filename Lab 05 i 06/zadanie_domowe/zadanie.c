#include <stdio.h>
#include <stdlib.h>

struct Person
{
    char name[10];
    char surname[20];
    int age;
};

typedef struct ListElement
{
    struct Person data;
    struct ListElement* next;

} LinkedList;

LinkedList* addHead(LinkedList *head, struct Person dta);
void displayList(LinkedList *head);
LinkedList* freeMem(LinkedList *head);
int listLen(LinkedList *head);

int main()
{

    LinkedList* head = NULL;

    // Dodaje 4 osoby na początek pustej listy

    // Dodaje kolejne 2 osoby na koniec listy
    
    // Wypisuje na ekran zawartość wszystkich węzłów od końca 
    
    // Usuwam dwa pierwsze elementy listy i ponownie wypisuje listę na ekran od końca
    


    // Usuwam utworzoną listę
    head = freeMem(head); // zeruje heada, listę, najważniejsze!!!
    head = NULL;


    return 0;
}

LinkedList* addHead(LinkedList *head, struct Person dta) // *head, bo chce wskaźnik na adres heada a nie zawartosc
{
    // 1. Alokacja pamięci
    LinkedList *new = (LinkedList*)malloc(sizeof(LinkedList)); // nowa komórka listy
    
    // 2. Zapisanie danych
    new->data = dta;
    new->next = head; // aktualny head, bo potem w lewo się przesuwam

    // 3. Dołączenie
    head = new; // nowa głowa, wskazuje na zawartosc jako new

    return head; // zwracam wskaznik, czyli adres heada, bo funkcja ma typ wskaznikowy

}

void displayList(LinkedList *head)
{
    LinkedList *tmp = head;

    while(tmp)
    {
        printf("Imie: %s, nazwisko: %s, wiek %d\n", tmp->data.name, tmp->data.surname, tmp->data.age);
        tmp = tmp->next;
    }
}

LinkedList* freeMem(LinkedList *head)
{
    LinkedList *tmp = head;

    while(tmp)
    {
        tmp = head->next; // zapamietuje dalszą część listy
        free(head);
        head = tmp;
    }

    return head;
}

int listLen(LinkedList *head)
{
    if(head == NULL)
    {
        return 0; // jak koniec listy, NULL
    }else
    {
        return 1 + listLen(head->next); // 1 + długość dalszej części listy
    }
}