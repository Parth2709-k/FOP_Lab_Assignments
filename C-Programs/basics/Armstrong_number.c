#include<stdio.h>
#include<math.h>

int main()
{
	int n, remainder, c=0, og;
	int result = 0;
	
	printf("Enter a three digit number: ");
	scanf("%d", &n);
	
	og = n;
	
	while(og!=0)
	{
		og /= 10;
		c++;
	}
	og = n;
	
	while(og!=0)
	{
		remainder = og % 10;
		result += pow(remainder,c);
		og /= 10;
	}
	
	if(result==n)
	{
		printf("%d is an armstrong number", n);
	}
	else
	{
		printf("%d is not an armstrong number", n);
	}
}
