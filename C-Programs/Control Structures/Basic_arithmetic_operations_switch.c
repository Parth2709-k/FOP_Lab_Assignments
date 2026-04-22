#include<stdio.h>
int main()
{
	int choice;
	int a, b;
	char ch;
	printf("Enter the first number: ");
	scanf("%d",&a);
	printf("Enter the second number: ");
	scanf("%d",&b);
	printf("1. Addition \n");
	printf("2. Subtraction \n");
	printf("3. Multiplication \n");
	printf("4. Division \n");
	printf("Enter your choice from 1 to 4: \n");
	scanf("%d",&choice);
	
	printf("Enter 'y' if you wish to continue");
	scanf(" %c", &ch);
	
	do
	{
		switch(choice)
		{
			case 1:
				printf("Addition is %d",a+b);
				break;
			case 2:
				printf("Subtraction is %d",a-b);
				break;
			case 3:
				printf("Multiplication is %d",a*b);
				break;
			case 4:
				if (b==0)
				{
				printf("Number can not be divided by 0");
				}
				else
				{
				printf("Division is %d",a/b);
				}
				break;
			case 5:
				printf("Invalid choice");
				break;
				
		}
	while(ch=='y');
	}

	
}

