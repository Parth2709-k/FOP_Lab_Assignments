# include<stdio.h>

int main()
{
  int a,d;
  printf("Enter the number:");
  scanf("%d",&a);
  
  while(a!=0)
  {
    d=a%10;
    printf(" Reversed number is %d",d);
    a=a/10;
  }
  return 0; 
}
