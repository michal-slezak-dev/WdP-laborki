#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int search(int arr[], int n, int target){
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
            return 1;
    }
    return 0;
}

//n a b, zwraca pointer do tablicy
int* gen(int n, int a, int b)
{
    int* arr = (int*)calloc(n, sizeof(int)); // calloc bo zeruje
    int i = 0;
    while(i < n)
    {
        int random_num = (rand() % (b - a + 1)) + a;
        while(search(arr, n, random_num) != 0)
            random_num = (rand() % (b - a + 1)) + a;

        arr[i] = random_num;
        i++;
    }

    return arr;
}

int main()
{   
    srand(time(NULL));
    // napisz funkcje, ktora wygeneruje n elementowa liczb losowych od a do b bez duplikatów
    int n = 0, a = 0, b = 0; // b - a + 1 > n musi byc
    
    scanf("%d", &n);
    while((b - a + 1) <= n){
        scanf("%d%d", &a, &b);
    }

    int* t = gen(n, a, b); 

    for(int i = 0; i < n; i++){
        printf("%d\n", *(t+i));

    }

    free(t);

    return 0;
}