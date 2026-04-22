#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  int n,i;
  printf("How many numbers you want to generate:");
  scanf("%d",&n);
  
  srand(time(0));
  
  for(i=0;i<n;i++)
  {
    printf("Number %d is : %d\n",i+1,rand());
  }
  
  return 0;
}
