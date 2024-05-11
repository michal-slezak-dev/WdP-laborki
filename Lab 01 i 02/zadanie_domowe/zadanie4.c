#include <stdio.h>

void sort_asc(int *a, int *b, int *c);

int main()
{
    int a = 0, b = 0, c = 0;
    printf("Podaj kolejno liczby calkowite a, b i c: ");
    scanf("%d%d%d", &a, &b, &c);

    printf("Liczby a, b i c przed sortowaniem:\n%d, %d, %d\n", a, b, c);

    sort_asc(&a, &b, &c);
    printf("Liczby a, b i c po posortowaniu rosnaco:\n%d, %d, %d\n", a, b, c);


    return 0;
}

void sort_asc(int *a, int *b, int *c) // można też teoretycznie jakieś sortowanie bąbelkowe zrobić ze wskaźnikami czy coś
{
    int temp = 0;

    if(*a > *b) 
    {
        temp = *b;
        *b = *a;
        *a = temp;     
    }
    if(*a > *c)
    {
        temp = *c;
        *c = *a;
        *a = temp;
    }
    if(*b > *c) // to ostatni if, bo wcześniej już zamieniłem a z c lub a z b, więc porównanie b z a itp. nie ma sensu
    {
        temp = *c;
        *c = *b;
        *b = temp;
    }

}