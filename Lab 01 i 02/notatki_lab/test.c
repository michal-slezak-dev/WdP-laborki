#include <stdio.h>

int main(){

     int x = 5;


     int * px = NULL; // obojêtnie gdzie * int *px / int* px
     px = &x; // wskaŸnik s³u¿y do przechowywania adresu
     printf("%d %p\n", x, &x); // wartoœæ i adres zmiennej x

     px++; // zmiana adresu o 4 bajty w prawo, mo¿na te¿ px-- w lewo-> rozmiar zmiennej, straci³em powi¹zanie do x o n * sizeof(typ)
     printf("%d %p adres x po zmianie o 4 bajty px %p\n", *px, &x, px);
     //*px = 8;
     printf("Adres o 4 bajty wiêkszy i wartoœc: %p, %d", px, *px); // nie mg przypisaæ, bo return != 0 i nie da siê, bo mo¿e byæ zajêty prze cos innego pamiêæ nie dla nas zarezerwowana

    char c;
    px = &c; // niekompatybilne, bo px to wskaŸni na inta a nie chara, mimo tego, ¿e kompilator to i tak dorbze powinien przesun¹æ o jeden a nie4

    //++ wy¿szy priorytet ni¿ *p

    return 0;
}
