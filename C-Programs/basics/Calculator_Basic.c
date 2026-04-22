# include<stdio.h>
# include<math.h>

int main() 
{
	int a,b,choice;
	long long fact=1;
	int ans;
	
	printf("1. Addition \n");
	printf("2. Subtraction \n");
	printf("3. Multiplication \n");
	printf("4. Division \n");
	printf("5. Raised to power \n");
	printf("6. Factorial \n");
	printf("7. Exit \n");
	
	printf("Enter the choice: ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1:
			printf("Enter the two numbers: ");
			scanf("%d %d",&a, &b);
			printf("Addition of the numbers is %d",a+b);
			break;
			
		case 2:
			printf("Enter the two numbers: ");
			scanf("%d %d",&a, &b);
			printf("Subtraction of the numbers is %d",a-b);	
			break;
			
		case 3:
			printf("Enter the two numbers: ");
			scanf("%d %d",&a, &b);
			printf("Multiplication of the numbers is %d",a*b);
			break;
			
		case 4:
			printf("Enter the two numbers: ");
			scanf("%d %d",&a, &b);
			if (b==0)
			{
				printf("Division can not be done by 0");
			}
			else
			{
				printf("Division of the numbers is %2f",a/b);
			}
			break;
			
		case 5:
			printf("Enter the base number: ");
			scanf("%d",&a);
			printf("Enter the number used as power: ");
			scanf("%d",&b);
			ans = pow(a,b);
			printf("Solution = %d", ans);
			break;
			
		case 6:
    
		    printf("Enter a positive integer: ");
		    scanf("%d", &a);
		    
		    if (a < 0) {
		        printf("Factorial not defined for negative numbers.\n");
		    } else {
		        for (int i = 1; i <= a; ++i) {
		            fact *= i;
		        }
		        printf("Factorial of %d = %ld\n", a, fact);  // Use %ld for long [web:12]
		    }
		    break;
		
		case 7:
			printf("\nExit");
			break;
			
		default:
			printf("Enter A Valid Choice");
			break;
				
	}
}
