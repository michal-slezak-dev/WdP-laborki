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
LinkedList* addTail(LinkedList *head, struct Person dta);
void displayList(LinkedList *head);
void displayReversedList(LinkedList *head);
LinkedList* freeMem(LinkedList *head, int delElementsNum);
int listLen(LinkedList *head);

int main()
{

    LinkedList* head = NULL;
    struct Person p1;

    // Dodaje 4 osoby na początek pustej listy
    for(int i = 0; i < 4; i++)
    {
        printf("Podaj imie %d. osoby: ", i + 1);
        scanf("%s", p1.name);

        printf("Podaj nazwisko %d. osoby: ", i + 1);
        scanf("%s", p1.surname);

        printf("Podaj wiek %d. osoby: ", i + 1);
        scanf("%d", &p1.age);

        head = addHead(head, p1);
    }

    // Dodaje kolejne 2 osoby na koniec listy
    for(int i = 0; i < 2; i++)
    {
        printf("Podaj imie %d. osoby: ", i + 5);
        scanf("%s", p1.name);

        printf("Podaj nazwisko %d. osoby: ", i + 5);
        scanf("%s", p1.surname);

        printf("Podaj wiek %d. osoby: ", i + 5);
        scanf("%d", &p1.age);

        head = addTail(head, p1);
        // if(head == NULL)
        // {
        //     head = tail;
        // }
    }
    
    // Wypisuje na ekran zawartość wszystkich węzłów od końca 
    // displayList(head);
    printf("\nLista wypisana od końca: \n");
    displayReversedList(head);

    // Usuwam dwa pierwsze elementy listy i ponownie wypisuje listę na ekran od końca
    head = freeMem(head, 2);
    printf("\nLista wypisana od końca po usunięciu 2 pierwszych elementów: \n");
    displayReversedList(head);

    // Usuwam utworzoną listę
    head = freeMem(head, 0); // zeruje heada, listę, najważniejsze!!!
    head = NULL;

    return 0;
}

LinkedList* addHead(LinkedList *head, struct Person dta) // *head, bo chce wskaźnik na adres heada a nie zawartosc
{
    // 1. Alokacja pamięci
    LinkedList *new = (LinkedList*)malloc(sizeof(LinkedList)); // nowa komórka listy
    
    // 2. Zapisanie danych
    new->data = dta;
    new->next = head; // zapisuje adres do pozostałej części listy, bo w lewo się przesuwam

    // 3. Dołączenie
    head = new; // nowa głowa, wskazuje na zawartosc jako new

    return head; // zwracam wskaznik na 1. element

}

LinkedList* addTail(LinkedList *head, struct Person dta) // właściwie to można zamiast head to tail nazwać
{
    // 1. Alokacja
    LinkedList *new = (LinkedList*)malloc(sizeof(LinkedList));

    // 2. Zapisanie danych
    new->data = dta;
    new->next = NULL;

    // 3. Dołączenie
    // tail = new;
    LinkedList *tmp = head;
    while(tmp->next)
    {
        tmp = tmp->next; // szukam ostatniego elementu listy, czyli jak next będzie NULL to kończę pętlę
    }
    tmp->next = new; // dodanie na koniec listy, dodaja nexta

    return head; // head zostaje, ale nexta koncowego zmieniam na new
}

void displayList(LinkedList *head)
{
    LinkedList *tmp = head;

    while(tmp) // póki nie natrafie na koniec listy po prawej
    {
        printf("Imie: %s, nazwisko: %s, wiek %d\n", tmp->data.name, tmp->data.surname, tmp->data.age);
        tmp = tmp->next;
    }
}

void displayReversedList(LinkedList *head)
{   
    if(head == NULL)
    {
        return; // warunek stop
    }else
    {
        displayReversedList(head->next); // najpierw najgłębsza się wykonuje, czyli ostatni element listy
        printf("Imie: %s, nazwisko: %s, wiek %d\n", head->data.name, head->data.surname, head->data.age);
    }
}

LinkedList* freeMem(LinkedList *head, int delElementsNum)
{
    LinkedList *tmp = head;

    if(delElementsNum == 0)
    {
        while(tmp)
        {
            tmp = head->next; // zapamietuje dalszą część listy
            free(head);
            head = tmp;
        }
    }else
    {
        int counter = 0;
        while(tmp)
        {
            if(counter == delElementsNum)
            {
                break;
            }

            tmp = head->next; // zapamietuje dalszą część listy
            free(head);
            head = tmp;
            counter++;
        }

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