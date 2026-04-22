#include <stdio.h>
#include <math.h>

int main() 
{
    int i, n;
    float x, degree, terms, sum;

    printf("Enter the angle in degrees: ");
    scanf("%f", &degree);

    printf("Enter the number of terms you want to execute: \n");
    scanf("%d", &n);

    x = degree * (M_PI / 180.0);

    terms = x; 
    sum = x;

    for (i = 1; i < n; i++) 
	{
        terms = (-1) * terms * x * x / ((2 * i) * (2 * i + 1));
        sum = sum + terms;
    }

    printf("Sum of sine series for %.2f degrees is: %.3f\n", degree, sum);
    return 0;
}

