#include<stdio.h>
int main()
{
    char*t[]={".----","..---","...--","....-",".....","-....","--...","---..","----.","-----"};
    char input[100];
    scanf("%s", input);
    for(int i=0;input[i];i++)
        printf("-%s",t[input[i]-'0']);//没想出来更好的办法
    printf("-\n");
    return 0;
}
