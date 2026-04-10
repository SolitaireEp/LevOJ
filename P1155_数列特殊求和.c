#include <stdio.h>
#include <stdlib.h>

long long mod(int base, int exp, int mod)
{
  long long result=1;
  long long b=base%mod;
  while(exp>0)
  {
    if(exp&1)
      result=(result*b)%mod;
    b=(b*b)%mod;
    exp>>=1;
  }
  return result;
}

int main()
{
  int a,b,i;
  long long s=0;
  scanf("%d %d",&a,&b);
  for(i=1;i<=a;i++)
    s=(s+mod(i,b,10000))%10000;
  printf("%d\n",(int)s);
  return 0;
}
