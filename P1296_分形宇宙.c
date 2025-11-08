#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100
char fractal[MAX][MAX];
void fun(int,int,int,int);

int main() 
{
    int n,i;
    scanf("%d", &n);
    int size = 1;
    for (i = 1; i < n; i++)
        size *= 3;
    for (i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
            fractal[i][j] = ' ';
    }
    fun(n, 0, 0, size);
    for (i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++)
            printf("%c", fractal[i][j]);
        printf("\n");
    }
    return 0;
}

void fun(int n, int x, int y, int size)
{
    if (n == 1) 
    {
        fractal[x][y] = 'X';
        return;
    }
    int new = size / 3;
    fun(n - 1, x, y, new);
    fun(n - 1, x, y + 2 * new, new);
    fun(n - 1, x + new, y + new, new);
    fun(n - 1, x + 2 * new, y, new);
    fun(n - 1, x + 2 * new, y + 2 * new, new);
}
