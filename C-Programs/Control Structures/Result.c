#include<stdio.h>

int main()
{
	int marks[5], i;
	int total;
	float average;
	int pass = 1;
	
	printf("Enter marks of 5 subjects: ");
	for(i=0;i<5;i++)
	{
		scanf("%d", &marks[i]);
		total  += marks[i];
		
		if(marks[i] < 40)
			pass = 0;
	}
	
	average = total/5.0;
	
	printf("Total Marks Of The Student Are: %d \n", total);
	printf("Average: %.2f \n", average);
	
	if(pass==0)
	{
		printf("Result = Fail \n");
	}
	else
	{
		printf("Result = Pass \n");
		
		
		if(average>=75)
			printf("Distinguished");
		else if(average>=60 && average<75)
			printf("First division");
		else if(average>=50 && average<60)
			printf("Second division");
		else if(average>=40 && average<50)
			printf("Third Division");
		else
			printf("No grade");
	}
		
}
