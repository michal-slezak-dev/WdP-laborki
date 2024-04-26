#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mem_alloc_err(int* arr);
void check_a_b_range(int n, int *a, int *b, char arr_symbol);
int search(int arr[], int n, int target);
int* gen(int n, int a, int b);
int matching_count(int arrA[], int arrB[], int n);
int* intersection(int n, int smae_count, int* arrA, int* arrB);

int main()
{
    /* U mnie funkcja2 to funkcja intersection */
    srand(time(NULL));

    int n = 0, a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    printf("Podaj dodatnia, calkowita liczbe elementow tablicy A i B n: ");
    scanf("%d", &n);
    
    // wprowadzenie danego zakresu losowania liczb [a;b] dla tablicy A i B
    check_a_b_range(n, &a1, &b1, 'A');
    check_a_b_range(n, &a2, &b2, 'B');



    int* arrA = gen(n, a1, b1);
    printf("Zawartosc tablicy A:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arrA[i]);
    }


    int* arrB = gen(n, a2, b2);
    printf("\n\nZawartosc tablicy B:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arrB[i]);
    }

    // przecięcie zbiorów
    int same_count = matching_count(arrA, arrB, n);
    int* arr_intersec = intersection(n, same_count, arrA, arrB);
    printf("\n\nCzesc wspolna tych tablic (iloczyn tych zbiorów ma %d takich samych elementów):\n", same_count);
    for(int i = 0; i < same_count; i++)
    {   
        printf("%d ", arr_intersec[i]);
    }
    
    free(arrA);
    free(arrB);
    free(arr_intersec);

    arrA = NULL;
    arrB = NULL;
    arr_intersec = NULL;

    return 0;
}

void mem_alloc_err(int* arr)
{
    if(arr == NULL)
    {
        printf("Nie udalo sie zaalokowac pamieci :-(");
        exit(1);
    }
}

void check_a_b_range(int n, int *a, int *b, char arr_symbol)
{
    while(1)
    {       
        printf("Podaj liczby a i b dla tablicy %c (zakres losowaia liczb do tablicy %c [a;b]): ", arr_symbol, arr_symbol);
        scanf("%d%d", a, b); // bez &, bo to już adresy sa (wskaźniki)
        if((*b - *a + 1) > n)
        {
            break;
        }else
        {
            printf("b - a + 1 musi być większe od n, aby wylosować unikalne liczby.\n\n");
        }
    }
}

int search(int arr[], int n, int target)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
            return 1;
    }
    return 0;
}

int* gen(int n, int a, int b)
{
    int* arr = (int*)calloc(n, sizeof(int));
    mem_alloc_err(arr);

    int random_num = (rand() % (b - a + 1)) + a;
    arr[0] = random_num; // pierwsza wartosc zawsze unikalna

    for(int i = 1; i < n; i++)
    {   
        while(search(arr, n, random_num) != 0)
        {
            random_num = (rand() % (b - a + 1)) + a;
        }
        arr[i] = random_num;
    }
    return arr;
}

int matching_count(int arrA[], int arrB[], int n)
{
    int same_count = 0;
    for(int i = 0; i < n; i++)
    {
        if(search(arrA, n, arrB[i]))
        {
            same_count++;
        }
    }
    return same_count;
}

int* intersection(int n, int same_count, int* arrA, int* arrB)
{   
    int* arr_intersec = (int*)calloc(same_count, sizeof(int)); 
    mem_alloc_err(arr_intersec);
    // printf("%d", same_count);

    int intersec_indx = 0;
    for(int i = 0; i < n; i++)
    {   
        if(search(arrA, n, arrB[i]))
        {
            arr_intersec[intersec_indx] = arrB[i]; // arrA[i] wsm to samo da
            intersec_indx++;
            // if(intersec_indx >= same_count)
            // {
            //     break;
            // }
        }        
    }

    return arr_intersec;
}