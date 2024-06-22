#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct ListElement
{
    int data;
    struct ListElement *next;
    struct ListElement *prev;
}DoubleLinkedList;

void check_a_b_range(int *a, int *b);
void mem_alloc_err(DoubleLinkedList* new);
// void addHead(DoubleLinkedList **head, DoubleLinkedList **tail, int key); // wsm to lepsza nazwa chyba by była addToHead i addToTail ;-)
void addToTail(DoubleLinkedList **head, DoubleLinkedList **tail, int key);
void deleteList(DoubleLinkedList **head, DoubleLinkedList **tail);
void displayList(DoubleLinkedList *tail);
void SortList(DoubleLinkedList **head, DoubleLinkedList **tail);

int main()
{
    srand(time(NULL));
    int n = 0, d = 0, a = 0, b = 0;
    DoubleLinkedList *head = NULL;
    DoubleLinkedList *tail = NULL;
    // deleteFirstHeadElement(&head, &tail);
    // deleteList(&head, &tail);

    printf("Podaj liczbe wezlow do dodania do listy: ");
    scanf("%d", &n);

    printf("Podaj liczby a i b dla listy (zakres losowaia danych(kluczy) do listy dwukierunkowej [a;b]): ");
    scanf("%d%d", &a, &b); // bez &, bo to już adresy sa (wskaźniki)

    check_a_b_range(&a, &b);
    // printf("%d %d", a, b);

    for(int i = 0; i < n; i++)
    {
        // printf("Podaj %d klucz do dodania: ", i + 1);
        // scanf("%d", &d);
        d = (rand() % (b - a + 1)) + a;


        addToTail(&head, &tail, d);
    }

    printf("\nNieuporzadkowana lista:\n");
    displayList(tail);

    SortList(&head, &tail);
    printf("\n\nUporzadkowana lista:\n");
    displayList(tail);

    deleteList(&head, &tail); // NULLuje też w środku funkcji

    return 0;
}

void check_a_b_range(int *a, int *b)
{   
    if(*b < *a)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

void mem_alloc_err(DoubleLinkedList* new)
{
    if(new == NULL)
    {
        printf("Nie udalo sie zaalokowac pamieci :-(");
        exit(1);
    }
}

// void addHead(DoubleLinkedList **head, DoubleLinkedList **tail, int key) //** bo adres heada chcemy i taila, na oryginale chcemy pracować
// {
//     // 1. Alokacja pamięci
//     DoubleLinkedList *new = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
//     mem_alloc_err(new);

//     // 2. Zapisanie danych
//     new->data = key;
//     new->next = new->prev = NULL; // w przypadku, gdy lista pusta jest

//     // new->next = *head; // zapisujemy dostęp jakby do dalszej części listy, zeby na 1. element wskazywal head, jeśli pusta to to co w 84. linijce będzie i tak

//     if(*head != NULL)
//     {
//         // (*head)->prev = new;
//         DoubleLinkedList *temp = *head;
//         while(temp != NULL && key >= temp->data) // miejsce wstawienia szukam
//         {
//             temp = temp->next; // musi byc rozne od null bo inaczej nie moznaby bylo wsadzic new i zpaisac nexta tempa
//         }

//         if(temp == *head)
//         {
//             //dodaje na poczatek
//             new->next = *head;
//             (*head)->prev = new;
//             *head = new;
//         }else if(temp == NULL)
//         {
//             // na koniec dodaje
//             new->prev = *tail;
//             (*tail)->next = new;
//             *tail = new;
//         }else // przypadek pomiedzy
//         {
//             new->next = temp;
//             new->prev = temp->prev;
            
//             temp->prev->next = new;
//             temp->prev = new;
//         }
//     }else // jeśli pusta lista to nowy element jest jednocześnie headem i tailem i sam uporzadkowany jest
//     {
//         *head = *tail = new;
//     }

//     // 3. Dołączenie danych
//     // *head = new; // wskazuje na zawartosc jako new
// }

void addToTail(DoubleLinkedList **head, DoubleLinkedList **tail, int key)
{   
    // 1. Alokacja pamięci
    DoubleLinkedList *new = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    mem_alloc_err(new);

    // 2. Zapisanie danych
    new->data = key;
    new->next = new->prev = NULL; // jeśli lista pusta to head = tail i na NULL wskazuje next i prev

    new->prev = *tail; // // zapisujemy dostęp jakby do dalszej części listy, zeby na ostatni element wskazywal tail, jeśli pusta to to co w 108. linijce będzie i tak

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


void displayList(DoubleLinkedList *tail) // potrzebuje zawartości
{
    if(tail)
    {
        displayList(tail->prev);
        // printf("Klucz: %d\n", tail->data);
        printf("%d ", tail->data);
    }
}

void SortList(DoubleLinkedList **head, DoubleLinkedList **tail)
{
    if(*head != NULL && (*head)->next != NULL) // tylko wtedy sortujemy, bo jak null to albo pusta, albo jeden element
    {
        // 1. Alokacja pamieci dla tempa, czyli zewnetrzny for do n - 1
        DoubleLinkedList *temp =  (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList)); // tu wsm mozna dac z buta ... = *head
        mem_alloc_err(temp);

        temp = *head;

        while(temp->next != NULL) // n - 1 odpowiednik
        {
            DoubleLinkedList *min = temp;
            DoubleLinkedList *temp2 = temp->next; // odpowiednik j = i + 1
            while(temp2 != NULL) // do n odpowiednik
            {
                if(temp2->data < min->data)
                {
                    min = temp2;
                }
                temp2 = temp2->next; // przechodze dalej w tej mniejszj liscie j++
            }
            //zamiana
            int tmp_val = temp->data;
            temp->data = min->data;
            min->data = tmp_val;        

            temp = temp->next; // i++ odpowiednik z petli
        }
    }
}