#include <stdio.h>

int main(){

     int x = 5;


     int * px = NULL; // oboj�tnie gdzie * int *px / int* px
     px = &x; // wska�nik s�u�y do przechowywania adresu
     printf("%d %p\n", x, &x); // warto�� i adres zmiennej x

     px++; // zmiana adresu o 4 bajty w prawo, mo�na te� px-- w lewo-> rozmiar zmiennej, straci�em powi�zanie do x o n * sizeof(typ)
     printf("%d %p adres x po zmianie o 4 bajty px %p\n", *px, &x, px);
     //*px = 8;
     printf("Adres o 4 bajty wi�kszy i warto�c: %p, %d", px, *px); // nie mg przypisa�, bo return != 0 i nie da si�, bo mo�e by� zaj�ty prze cos innego pami�� nie dla nas zarezerwowana

    char c;
    px = &c; // niekompatybilne, bo px to wska�ni na inta a nie chara, mimo tego, �e kompilator to i tak dorbze powinien przesun�� o jeden a nie4

    //++ wy�szy priorytet ni� *p

    return 0;
}
