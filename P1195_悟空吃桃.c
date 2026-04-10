#include <stdio.h>

int main()
{
  int n,i;
  long long ori;
  scanf("%d",&n);
  ori=1;
  for(i=1;i<n;i++)
    ori = 2*(ori+1);
  printf("%lld\n",ori);
  return 0;
}
