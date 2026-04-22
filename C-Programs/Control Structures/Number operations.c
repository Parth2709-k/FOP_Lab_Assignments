#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, fact = 1, flag=1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n >= 0)
        printf("\nSquare root of %d = %.2f", n, sqrt(n));
    else
        printf("\nSquare root not defined for negative numbers");

	int sqr = pow(n,2);
    printf("\nSquare of %d = %d", n, sqr);

	int cub = pow(n,3);
    printf("\nCube of %d = %d", n, cub);


    if (n <= 1)
        printf("Factorial for numbers smaller than 1 is not defined");
    else
    {
        for (i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                flag = 0;
                break;
            }
        }
    }

    if (flag == 1)
        printf("\n%d is a Prime number", n);
    else
        printf("\n%d is NOT a Prime number", n);

    if (n < 0)
        printf("\n Factorial is not defined for negative numbers");
    else
    {
        for (i = 1; i <= n; i++)
            fact = fact * i;

        printf("\nFactorial of %d = %d", n, fact);
    }


    printf("\nPrime factors of %d are: ", n);
    for (i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            printf("%d ", i);
            n = n / i;
        }
    }

    return 0;
}

