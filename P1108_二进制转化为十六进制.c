#include <stdio.h>
#include <string.h>

int main()
{
  char b[200001]={0};
  char hex[50001]={0};
  int len,idx,i,j;
  scanf("%s",b);
  len=(int)strlen(b);
  idx=0;
  i=len-1;
  while(i>=0)
  {
    int value,weight;
    value=0;
    weight=1;
    for(j=0;j<4 && i>=0;j++,i--)
    {
      if(b[i]=='1')
        value+=weight;
      weight*=2;
    }
    if(value<10)
      hex[idx++]='0'+value;
    else
      hex[idx++]='A'+(value-10);
  }
  for(j=idx-1;j>=0;j--)
    putchar(hex[j]);
  putchar('\n');
  return 0;
}
