#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement
{
    int data;
    struct ListElement *next;
    struct ListElement *prev;
}DoubleLinkedList;

void addHead(DoubleLinkedList **head, DoubleLinkedList **tail, int key); // wsm to lepsza nazwa chyba by była addToHead i addToTail ;-)
void addTail(DoubleLinkedList **head, DoubleLinkedList **tail, int key);
void deleteList(DoubleLinkedList **head, DoubleLinkedList **tail);
void deleteFirstHeadElement(DoubleLinkedList **head, DoubleLinkedList **tail);
void displayList(DoubleLinkedList *tail);


int main()
{
    int n1 = 0, n2 = 0, d = 0;
    DoubleLinkedList *head = NULL;
    DoubleLinkedList *tail = NULL;
    // deleteFirstHeadElement(&head, &tail);
    // deleteList(&head, &tail);

    printf("Podaj liczbe wezlow do dodania na poczatek listy: ");
    scanf("%d", &n1);

    for(int i = 0; i < n1; i++)
    {
        printf("Podaj %d klucz do dodania: ", i + 1);
        scanf("%d", &d);

        addHead(&head, &tail, d);
    }

    printf("\nWszyskie wezly od poczatku: \n");
    displayList(tail);
    // deleteFirstHeadElement(&head, &tail);
    // deleteList(&head, &tail);
    // displayList(tail);

    printf("Podaj liczbe wezlow do dodania na koniec listy: ");
    scanf("%d", &n2);

    for(int i = 0; i < n2; i++)
    {
        printf("Podaj %d klucz do dodania: ", i + 1);
        scanf("%d", &d);

        addTail(&head, &tail, d);
    }

    // printf("\nWszystkie wezly od poczatku, po dodaniu danej liczby wezlow na koniec:\n");
    // displayList(tail);

    deleteFirstHeadElement(&head, &tail);
    printf("\nWszystkie wezly wypisane od poczatku, po usunieciu pierwszego elementu, na ktory wskazywala glowa:\n");
    displayList(tail);

    deleteList(&head, &tail); // NULLuje też w środku funkcji

    return 0;
}

void addHead(DoubleLinkedList **head, DoubleLinkedList **tail, int key) //** bo adres heada chcemy i taila, na oryginale chcemy pracować
{
    // 1. Alokacja pamięci
    DoubleLinkedList *new = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));

    // 2. Zapisanie danych
    new->data = key;
    new->next = new->prev = NULL; // w przypadku, gdy lista pusta jest

    new->next = *head; // zapisujemy dostęp jakby do dalszej części listy, zeby na 1. element wskazywal head, jeśli pusta to to co w 33. linijce będzie i tak

    if(*head != NULL) //  jesli niepusta to tail zostaje tam gdzie był początkowo
    {
        (*head)->prev = new;
    }else // jeśli pusta lista to nowy element jest jednocześnie headem i tailem
    {
        *tail = new;
    }

    // 3. Dołączenie danych
    *head = new; // wskazuje na zawartosc jako new
}

void addTail(DoubleLinkedList **head, DoubleLinkedList **tail, int key)
{   
    // 1. Alokacja pamięci
    DoubleLinkedList *new = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));

    // 2. Zapisanie danych
    new->data = key;
    new->next = new->prev = NULL; // jeśli lista pusta to head = tail i na NULL wskazuje next i prev

    new->prev = *tail; // // zapisujemy dostęp jakby do dalszej części listy, zeby na ostatni element wskazywal tail, jeśli pusta to to co w 75. linijce będzie i tak

    if(*tail != NULL)
    {
        (*tail)->next = new;
        // *tail = new;
    }else
    {
        // *tail = *head = new;
        *head = new;
    }

    *tail = new;
}

void deleteList(DoubleLinkedList **head, DoubleLinkedList **tail)
{
    DoubleLinkedList *tmp = *head;
    while(*head)
    {
        tmp = (*head)->next; // zapamietuje dalsza czesc listy
        free(*head);
        *head = tmp;
    }

    *head = *tail = NULL;
}

void deleteFirstHeadElement(DoubleLinkedList **head, DoubleLinkedList **tail)
{   
    if(*head != NULL) // jeśli lista nie jest pusta, bo jak pusta to nic nie usuwamy, bo lista jest pusta
    {
        DoubleLinkedList *tmp = *head;
        // if((*head)->prev == NULL) // to wsm niepotrzebne, bo head przeciez wskazuje prevem na NULL
        // {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
        // }
        if(*head != NULL) // przypadek jeśli tylko 1 element był listy
        {
            (*head)->prev = NULL; // tu musze dodać, bo pierwotnie kolejny element, wskazywal w  previe na heada, ale 1. element usunalem, wiec musze ustawic prev nowego heada na NULL
        }else // jeśli tylko 1 element i head to NULL to też tail musi być NULL
        {
            *tail = NULL;
        }
    }
}

void displayList(DoubleLinkedList *tail) // potrzebuje zawartości
{
    if(tail)
    {
        displayList(tail->prev);
        printf("Klucz: %d\n", tail->data);
    }
}
