#include <stdio.h>
#include <string.h>
int main()
{
 char s[101] = {0};
 char output[101] = {0};
 int i,k,len;
 scanf("%d",&k);
 scanf("%s",s);
 len = strlen(s);
 for (i=0;i<len;i++)
  output[i] = s[(i+k)%len]; //评测数据有大写字符；一次移位，无需k次循环
 printf("%s",output);
 return 0;
}
