#include <stdio.h>

int ways(int x, int y)
{
    if (x == 0 || y == 1)
        return 1;
    if (x < y)
        return ways(x, x);
    else
        return ways(x, y - 1) + ways(x - y, y);
}
int main()
{
    int m, n;
    scanf("%d %d",&m,&n);
    int w = ways(m, n);
    printf("%d",w);
}
