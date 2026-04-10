#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  char isbn[14];
  scanf("%d",&T);
  while(T--)
  {
    int i,m;
    int d=1;
    int s=0;
    scanf("%s",isbn);
    for(i=0;i<11;i++)
    {
      if(isbn[i]=='-')
        continue;
      s+=((isbn[i]-'0')*(d++));
    }
    m=s%11;
    if(m==(isbn[12]-'0'))
      printf("Right\n");
    else if(m==10)
    {
      isbn[12]='X';
      printf("%s\n",isbn);
    }
    else
    {
      isbn[12]=m+'0';
      printf("%s\n",isbn);
    }
  }
  return 0;
}
