#include <stdio.h>
#include <string.h>
#define MAX 202
int a[MAX] = { 0 }, b[MAX] = { 0 }, c[MAX] = { 0 };

int read(int arr[])
{
    char s[MAX];
    if (scanf("%s", s) != 1) return 0;
    int len = strlen(s);
    arr[0] = len;
    for (int i = 1; i <= len; i++)
        arr[i] = s[len - i] - '0';
    return 1;
}

void subtract(int x[], int y[], int c[])
{
    int i;
    for (i = 1; i <= x[0]; i++)
        c[i] = x[i] - (i <= y[0] ? y[i] : 0);
    for (i = 1; i <= x[0]; i++)
    {
        if (c[i] < 0)
        {
            c[i] += 10;
            int j = i + 1;
            while (c[j] == 0 && j <= x[0])
            {
                c[j] = 9;
                j++;
            }
            c[j] -= 1;
        }
    }
    int len = x[0];
    while (len > 1 && c[len] == 0) len--;
    c[0] = len;
}

void print_int(int c[])
{
    for (int i = c[0]; i >= 1; i--)
        printf("%d", c[i]);
    printf("\n");
}

int main() 
{
    read(a);
    read(b);
    subtract(a, b, c);//仔细读题啊...一开始还考虑了结果为0和负数直接被判WA
    print_int(c);
    return 0;
}
