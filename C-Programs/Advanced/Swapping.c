#include <stdio.h>

void swapNoPointers(int a, int b) 
{
    int temp = a;
    a = b;
    b = temp;
    printf("Inside function (No Pointers): a = %d, b = %d\n", a, b);
}

void swapWithPointers(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
    int x = 10, y = 20;

    printf("Original: x = %d, y = %d\n", x, y);

    swapNoPointers(x, y);
    printf("After swappping without pointers: x = %d, y = %d\n", x, y);

    swapWithPointers(&x, &y);
    printf("After Swapping using pointers: x = %d, y = %d\n", x, y);

    return 0;
}

