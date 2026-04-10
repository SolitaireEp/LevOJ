#include <stdio.h>
int prime(int n)
{
  int i;
  if(n<2)
    return 0;
  if(n==2)
    return 1;
  if(n%2==0)
    return 0;
  for(i=3;i<=(n/2);i+=2)
  {
    if(n%i==0)
      return 0;
  }
  return 1;
}
int reverse(int n)
{
  int rev=0;
  while(n>0)
  {
    rev=rev*10+(n%10);
    n/=10;
  }
  return rev;
}

int main()
{
  int n,x,rev;
  scanf("%d",&n);
  while(n--)
  {
    scanf("%d",&x);
    rev = reverse(x);
    if(prime(x) && prime(rev))
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}
