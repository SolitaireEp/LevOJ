#include<stdio.h>
#include<string.h>
int a[201]={0},b[201]={0};
void init(int a[])
{
 int i=0,len=0;
 char s[205];
 while ((s[i++]=getchar())!='\n' && i<201);
 s[i-1]='\0';
 len=a[0]=strlen(s);
 for(i=1;i<=len;i++)
 a[i]=s[len-i]-'0';
}
void print(int a[])
{
 int i;
 if (a[0]==0)
 {
 printf("0\n");
 return;
 }
 for(i=a[0];i>0;i--)
 printf("%d",a[i]);
 printf("\n");
 return;
}
void add(int a[],int b[])
{
 int i,k;
 if(a[0]<b[0])
 a[0]=b[0];
 for(i=1;i<=a[0];i++)
 {
 a[i]+=b[i];
 a[i+1]+=a[i]/10;
 a[i]%=10;
 }
 if(a[a[0]+1]>0)
 a[0]++;
}
int main()
{
 init(a);
 init(b);
 add(a,b);
 print(a);
 return 0;
}
