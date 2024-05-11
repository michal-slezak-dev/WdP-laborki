#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int random_num_gen(int a, int b);
int swap_num(int *a, int *b);
void find_min_max(int *tab, int n, int *min, int *max);

int main()
{   
    srand(time(NULL));
    
    int n;
    printf("Podaj liczbe elementow tablicy: ");
    scanf("%d", &n);

    int arr[n];
    int *ip = arr; // &tab[0]

    int a = 0, b = 0;
    printf("Podaj zakres, z ktorego chcesz wylosowac liczby [a;b]: ");
    scanf("%d%d", &a, &b);

    if(a > b)
    {
        swap_num(&a, &b);
    }


    //wypełniam tablice randomowymi liczbami
    for(int i = 0; i < n; i++)
        *(ip + i) = random_num_gen(a, b);

    printf("Elementy tablicy: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(ip + i));  
    printf("\n");

    int min = *(arr), max = *(arr); // można też w funkcji od razu
    // printf("%d %d", min, max);
    find_min_max(arr, n, &min, &max); // wyłaniam max i min jednocześnie zgodnie z poleceniem, przekazując początkowo adresy min i max

    printf("Min: %d\nMax: %d", min, max);

    return 0;
}

int random_num_gen(int a, int b)
{
    int random_num = rand() % (b - a + 1) + a;

    return random_num;
}

int swap_num(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void find_min_max(int *tab, int n, int *min, int *max)
{
    for(int i = 1; i < n; i++)
    {
        if(*(tab + i) < *min)
        {
            *min = *(tab + i);
        }

        if(*(tab + i) > *max)
        {
            *max = *(tab + i);
        }
    }
}