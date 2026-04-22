#include<stdio.h>
int main()
{
	int choice;
	int a, b;
	printf("Enter the first number:");
	scanf("%d",&a);
	printf("Enter the second number:");
	scanf("%d",&b);
	printf("1. Addition");
	printf("2. Subtraction");
	printf("3. Multiplication");
	printf("4. Division");
	printf("Enter your choice from 1 to 4:");
	scanf("%d",&choice);
	if (choice==1)
	{
		printf("Addition is %d",a+b);
	}
	else if (choice==2)
	{
		printf("Subtraction is %d",a-b);
	}
	else if (choice==3)
	{
		printf("Multiplication is %d",a*b);
	}
	else if (choice==4)
	{
		if (b==0){printf("Number can not be divided by 0");}
		else{printf("Division is %d",a/b);}
	}
	else 
	{
		printf("Enter valid choice");
	}
	return 0;
}
