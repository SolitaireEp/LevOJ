#include <stdio.h>

int diedai(int n)
{
  int a=1,b=2,c,i;
  if(n==1)
    return 1;
  if(n==2)
    return 2;
  for(i=3;i<=n;i++)
  {
    c=a+b;
    a=b;
    b=c;
  }
  return b;
}

int main()
{
  int n;
  scanf("%d",&n);
  printf("%d\n",diedai(n));
  return 0;
}
