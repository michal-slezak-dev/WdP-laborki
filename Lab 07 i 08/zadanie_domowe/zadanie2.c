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
        arr[i] = rand()%20;
        // scanf("%d", &arr[i]);
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
    int firstIndx = 0, lastIndx = 0, tmpMin = 0, tmpMax = 0;
    for(int i = 0; i < n / 2; i++) // n / 2, bo jednocześnie sortujemy przecież
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

        // zmienne pomocnicze
        tmpMin = i;
        tmpMax = n - i - 1;

        if(arr[tmpMin] > arr[lastIndx]) // wtedy to wartosc pod tmpMin najwieksza aktualnie
        {
            lastIndx = tmpMin;
        }

        if(arr[tmpMax] < arr[firstIndx])
        {
            firstIndx = tmpMax;
        }

        // zamiana z minimum i pierwszy element z tablicy
        if(firstIndx != tmpMin) // jeśli równe tzn. że już na swoim miejscu jest
        {
            // int temp = arr[firstIndx];
            // arr[firstIndx] = arr[tmpMin];
            // arr[tmpMin] = temp;
            swap(&arr[tmpMin], &arr[firstIndx]);

            if(lastIndx == tmpMin) // wtedy lastIndex na złej pozycji jest
            {
                lastIndx = firstIndx;
            }
        }

        //zamiana z maximum i ostatni element tablicy
        if(lastIndx != tmpMax)
        {
            // int temp = arr[lastIndx];
            // arr[lastIndx] = arr[tmpMax];
            // arr[tmpMax] = temp;
            swap(&arr[tmpMax], &arr[lastIndx]);
        }
    }
    // printf("\n\nT%d %d\n", firstIndx, lastIndx);
}