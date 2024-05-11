#include <stdio.h>

void swap_func(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b =  temp;
}


int main(){
      // normalnie dofunckji przekazuje kopie argumenti, ale dzieki wskaznikom mozna oryginal przekazac jesli np chce kilka rzeczy zwrocic

    int a = 5, b = 2;
    swap_func(&a, &b);
    printf("%d, %d", a, b);
// œroda 24:00 10
    return 0;
}
