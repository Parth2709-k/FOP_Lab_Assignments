#include <stdio.h>

void ArrayInput(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
	{
        printf("Enter element for array %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void EvenOddpartition(int arr[], int n) 
{
    printf("\nEven Numbers: ");
    for (int i = 0; i < n; i++) 
	{
        if (arr[i] % 2 == 0)
            printf("%d ", arr[i]);
    }

    printf("\nOdd Numbers: ");
    for (int i = 0; i < n; i++) 
	{
        if (arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int arr[100], n;

    printf("----- EVEN-ODD PARTITION -----\n");
    printf("Enter number of elements of array: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) 
	{
        printf("Invalid size!\n");
        return 1;
    }

    ArrayInput(arr, n);
    EvenOddpartition(arr, n);

    return 0;
}
