#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mem_alloc_err(int* arr);
int search(int arr[], int n, int target);
int* gen(int n, int a, int b);
int* copy(int n, int* arr);

int main()
{
    /* U mnie funkcja1 to funkcja copy */
    srand(time(NULL));

    int n = 0, a = 0, b = 0;
    printf("Podaj dodatnia, calkowita liczbe elementow tablicy n: ");
    scanf("%d", &n);

    while(1)
    {       
        printf("Podaj liczby a i b (zakres losowaia liczb do tablicy [a;b]): ");
        scanf("%d%d", &a, &b);
        if((b - a + 1) > n)
        {
            break;
        }else
        {
            printf("b - a + 1 musi być większe od n, aby wylosować unikalne liczby.\n\n");
        }
    }

    int* arr = gen(n, a, b);
    printf("\nTablica zrodlowa:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // kopia
    int* arr_copy = copy(n, arr);
    printf("\n\nKopia tablicy zrodlowej:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr_copy[i]);
    }

    free(arr); // najważniejsze!!!
    free(arr_copy);

    arr = NULL; // zabezpieczenie!!!
    arr_copy = NULL;

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

int* copy(int n, int* arr)
{
    int* arr_copy = (int*)calloc(n, sizeof(int));
    mem_alloc_err(arr_copy);

    for(int i = 0; i < n; i++)
    {
        arr_copy[i] = *(arr + i); //;-)
    }

    return arr_copy;
}