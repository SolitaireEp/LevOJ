#include <stdio.h>

int prime(int n)
{
  int j,isprime=1;
  for(j=2;j<n;j++)
  {
    if(n%j==0)
    isprime=0;
  }
  return isprime;
}

int main()
{
  int n,i;
  int m=0;
  scanf("%d",&n);
  for(i=2;i<n;i++)
  {
    if(n%i==0 && prime(i) && prime(n/i))
    m=1;
  }
  if(m==1)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
