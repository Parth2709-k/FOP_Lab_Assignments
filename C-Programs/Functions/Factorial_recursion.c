#include<stdio.h>

int recursive_fact(int n)
{
	if(n==0)
		return 1;
	else
		return n*recursive_fact(n-1);
}

int factorial(int n)
{
	int c = 1, i;
	for(i=1;i<=n;i++)
		c = c*i;
	return c;
}

int main()
{
	int num;
	printf("Enter a Number: ");
	scanf("%d", &num);
	
	printf("Factorial Using Recursion is = %d \n", recursive_fact(num));
	printf("Factorial Without Using Recursion is = %d \n", factorial(num));
	
	return 0;
}


