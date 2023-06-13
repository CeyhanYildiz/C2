
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{
    int numbers;
    int* ptr;

    ptr = number; // Invalid
    *ptr = &number; // Invalid
    ptr = &number // Valid
    *ptr = number; // Valid

    int b = 42;
    int *a = &b;


    printf("b: %d\n", b);
    printf("&b: %p\n", &b);
    printf("a: %p\n", a);


    *a = 50;


    printf("b: %d\n", b);
    printf("&b: %p\n", &b);
    printf("a: %p\n", a);



    int m, n, p;
    m = n = p = 0;


    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &m, &n, &p);
    printf("Result: %d\n", m + n + p);


    int x, y;
    x = 5;
    y = 10;


    printf("x: %d, y: %d\n", x, y);
    printf("&x: %p\n&y: %p\n", &x, &y);


    swap(&x, &y);

    printf("x: %d, y: %d\n", x, y);



    int *d;
    int length = 0;
    printf("Enter a length: ");
    scanf("%d", &length);


    d = malloc(length * sizeof(int));


    printf("d: %p\n", d);


    for (int i = 0; i < length; i++)
    {
        d[i] = i;
    }
    

    for (int i = 0; i < length; i++)
    {
            printf("d[%d]=%d\n", i, d[i]);
    }
    


    free(d);

    return 0;
}


void swap(int *a, int *b)
{

    printf("a: %p\nb: %p\n", a, b);
    printf("*a: %d\n*b: %d\n", *a, *b);


    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}