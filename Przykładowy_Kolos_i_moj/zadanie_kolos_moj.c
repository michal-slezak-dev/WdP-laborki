#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mem_alloc_err(int* arr);
void check_a_b_range(int n, int *a, int *b, char arr_symbol);
int search(int arr[], int n, int target);
int* gen(int n, int a, int b);
int matching_count(int arrA[], int arrB[], int n);
int* symetric_diff(int n, int* arrA, int* arrB, int* c_count);

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


    // roznica symetryczna, czyli to co nie ma w iloczynie
    // int same_count = matching_count(arrA, arrB, n); // tez jako argument funkcji mozna dac wsm
    int c_count = 0;
    int* arr_sym_diff = symetric_diff(n, arrA, arrB, &c_count);
    printf("\n\nRoznica symetryczna tych dwoch tablic (Tablica C) to (Tablica C ma %d elementow):\n", c_count);
    for(int i = 0; i < c_count; i++)
    {   
        printf("%d ", arr_sym_diff[i]);
    }
    
    free(arrA);
    free(arrB);
    free(arr_sym_diff);

    arrA = NULL;
    arrB = NULL;
    arr_sym_diff = NULL;

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

int* symetric_diff(int n, int* arrA, int* arrB, int* c_count)
{   
    int same_count = matching_count(arrA, arrB, n);
    int* arr_intersec = (int*)calloc(same_count, sizeof(int)); 
    mem_alloc_err(arr_intersec);

    // iloczyn
    int intersec_indx = 0;
    for(int i = 0; i < n; i++)
    {   
        if(search(arrA, n, arrB[i]))
        {
            arr_intersec[intersec_indx] = arrB[i]; // arrA[i] wsm to samo da
            intersec_indx++;
        }        
    }

    int counter = 0; // ile jest w tablicy C w tej roznicy symetrycznej, zgodnie z def. czyli search jak 0 bedzie dla arrA i arrB to licznik zwiekszamy
    // elementy nalezace do A i nienalezace do B i elementy nalezace do B i nienalezace do A?

    // z def. z polecenia
    for(int j = 0; j < n; j++)
    {
        if(!search(arrB, n, arrA[j])) // tylko w B
        {
            counter++;
        }     
    }

    for(int k = 0; k < n; k++)
    {
        if(!search(arrA, n, arrB[k])) // tylko w A
        {
            counter++;
        } 
    }

    *c_count = counter;
    int* arr_symetric_diff = (int*)calloc(*c_count, sizeof(int));
    mem_alloc_err(arr_symetric_diff);

    //symetryczna roznica
    int sym_diff_indx = 0;
    for(int j = 0; j < n; j++)
    {
        if(!search(arr_intersec, n, arrA[j])) // tez innymi slowy to co nie ma w iloczynie, bo mozna to samo dac co przy lcizeniu countera
        {
            arr_symetric_diff[sym_diff_indx] = arrA[j]; 
            sym_diff_indx++;
        }     
    }

    for(int k = 0; k < n; k++)
    {
        if(!search(arr_intersec, n, arrB[k]))
        {
            arr_symetric_diff[sym_diff_indx] = arrB[k];
            sym_diff_indx++;
        } 
    }

    free(arr_intersec);
    arr_intersec = NULL; // tu juz moge zwolnic, bo potem nie korzystam z tego

    return arr_symetric_diff; // tabC
}