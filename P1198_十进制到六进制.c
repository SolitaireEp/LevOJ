#include <stdio.h>
#include <string.h>

void dectohex(int n,char*hex)
{
  if(n==0)
  {
    strcpy(hex,"0");
    return;
  }
  char temp[35];
  int r;
  int idx=0,negative=0;
  if(n<0)
  {
    negative=1;
    n=-n;
  }
  while(n>0)
  {
    r=n%6;
    temp[idx++]='0'+r;
    n/=6;
  }
  int i;
  int pos=0;
  if(negative)
    hex[pos++]='-';
  for(i=idx-1;i>=0;i--)
    hex[pos++]=temp[i];
  hex[pos]='\0';
}

int main()
{
  int n,num;
  char hex[35];
  scanf("%d",&n);
  while(n--)
  {
    scanf("%d",&num);
    dectohex(num,hex);
    printf(hex);
    printf("\n");
  }
  return 0;
}
