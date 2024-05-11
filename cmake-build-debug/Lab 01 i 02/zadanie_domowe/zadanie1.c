#include <stdio.h>

int main()
{
    //1.
    int a, b;
    int *c, *d;
    c = &a;
    a = 3;
    d = c;
    b = 6;

    printf("%d %d %d %d\n", a, b, *c, *d);

    //2.
    c = &a;
    a = 3;
    d = c;
    b = 6;
    *c = 4;

    printf("%d %d %d %d\n", a, b, *c, *d);

    //3.
    c = &a;
    a = 3;
    d = &b;
    b = 6;
    *c = *d;

    printf("%d %d %d %d\n", a, b, *c, *d);
    return 0;
}