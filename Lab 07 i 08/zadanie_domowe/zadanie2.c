#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mem_alloc_err(int *arr);
void swap(int *a, int *b);
void selection_sort(int arr[], int n);

int main()
{
    srand(time(NULL));
    int n = 0;

    printf("Podaj liczbe elementow tablicy do wylosowania, losujemy liczby z zakresu 0-20: ");
    scanf("%d", &n);

    int* arr = (int*)calloc(n, sizeof(int));
    mem_alloc_err(arr);

    for(int i = 0; i < n; i++)
    {
        // arr[i] = rand()%20;
        scanf("%d", &arr[i]);
    }

    printf("Tablica przed posortowaniem:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTablica po posortowaniu:\n");
    selection_sort(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);


    free(arr);
    arr = NULL;

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

void swap(int *a, int *b)
{
    int tmp = *a; // wartość wyłuskuje
    *a = *b;
    *b = tmp;
}

void selection_sort(int arr[], int n)
{
    int firstIndx = 0, lastIndx = 0;
    for(int i = 0; i < n - 1; i++) // n - 1, bo j = i + 1, żeby nie wyszło poza zakres
    {
        firstIndx = i;
        lastIndx = n - i - 1; // aktualny ostatni element
        for(int j = i + 1; j < n - i; j++)
        {
            if(arr[j] < arr[firstIndx])
            {
                firstIndx = j;
            }

            if(arr[j] > arr[lastIndx])
            {
                lastIndx = j;
            }
        }

        // zamiana z minimum i pierwszy element z tablicy
        if(firstIndx != i)
        {
            int temp = arr[firstIndx];
            arr[firstIndx] = arr[i];
            arr[i] = temp;
        }

        //zamiana z maximum i ostatni element tablicy
        if(lastIndx != n - i - 1)
        {
            int temp = arr[lastIndx];
            arr[lastIndx] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }



    }
    // printf("\n\nT%d %d\n", firstIndx, lastIndx);
}