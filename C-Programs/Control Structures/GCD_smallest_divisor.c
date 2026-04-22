#include <stdio.h>

int main()
{
  int a, b, x, y, gcd;
  int i, smallestDivisor, min;
  
  printf("Enter two numbers:");
  scanf("%d %d",&a,&b);
  
  x=a;
  y=b;
  
  while(y!=0)
  {
    int temp=y;
    y=x%y;
    x=temp;
  }
  gcd=x;
  
  min = (a<b) ? a:b;
  i=2;
  smallestDivisor=0;
  
  while(i<=min)
  {
    if(a%i==0 && b%i==0)
    {
      smallestDivisor=i;
      break;
    }
    i++;
  }
  
  printf("Greatest Common Divisor= %d\n",gcd);
  
  if(smallestDivisor !=-0)
  {
    printf("Smallest Common Divisor= %d\n",smallestDivisor);
  }
  else
  {
    printf("Smallest Common Divisor= 1");
  }
  
  return 0;
}
