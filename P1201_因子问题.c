#include <stdio.h>

int samefactor(int n,int m)
{
  int min,i;
  min= n<m?n:m;
  for(i=1;i<min;i++)
  {
    if(n%i==0 && n%(m-i)==0)
    break;
  }
  return i;
}

int main()
{
  int K,m,n,a;
  scanf("%d",&K);
  while(K--)
  {
    scanf("%d",&n);
    scanf("%d",&m);
    a=samefactor(n,m);
    if(a==m)
      a=-1;
    printf("%d\n",a);
  }
  return 0;
}
