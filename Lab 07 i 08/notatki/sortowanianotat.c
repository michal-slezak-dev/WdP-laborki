#include <stdio.h>
#include <stdlib.h>

// selection sort

int* find_min(int* tabl, int n);
void selection_sort(int tabl[], int n);

int main()
{

    int* tabl = (int*)calloc(10, sizeof(int));
    int n = 10;
    for(int i = 0; i < n; i++)
    {
        tabl[i] = rand()%20;
    }

    for(int i = 0; i < n; i++)
        printf("%d ", tabl[i]);
    
    selection_sort(tabl, n);
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d ", tabl[i]);

    free(tabl);
    return 0;
}

void selection_sort(int tabl[], int n) // lub *tabl
{

    int indx = 0;
    for(int i = 0; i < n - 1; i++)
    {   
        indx = i; //  zapamietuje index pierwszego elementu, zeby potem zamienic
        for(int j = i + 1; j < n; j++) // j = i bo szukamy minimalnego elementu z calej tablicy, i+ 1 bo zapamietalem sobie index pierwszy jako 0
        {
            //szukam min
            if(tabl[j] < tabl[indx])
            {
                indx = j;
            }
        }

        //swapuje
        // swap(tabl[i], tabl[indx]);
        int temp = tabl[i];
        tabl[i] = tabl[indx];
        tabl[indx] = temp;
    }


    // int minValIndx = 0;
    // for(int i = 0; i < n - 1; i++) // ostatni element bedzie poosrtowany i tak, na ktory pozycje element minimalny
    // {
    //     int minVal = *(tabl + i);
    //     // int minValIndx = i;
    //     for(int j = i; j < n; j++) // szukam indeksu minimalnego
    //     {
    //         if(*(tabl + j) < minVal)
    //         {
    //             // minVal = *(tabl + j);
    //             minValIndx = j;
    //         }
    //     }

    //     // swapowanie
    //     int temp = minVal;
    //     *(tabl + i) = *(tabl + minValIndx);
    //     *(tabl + minValIndx) = temp;
    // }
}

// void swap_func(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b =  temp;
// }