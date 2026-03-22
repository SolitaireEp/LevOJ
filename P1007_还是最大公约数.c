#include <stdio.h>
int gcd(int x, int y) //欧几里得算法
{
    int t;
    while (y!=0) 
    {
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

int main()
{
    int n,i,a,b,c,r;
	scanf("%d", &n);
    for (i=0;i<n;i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        r = gcd(gcd(a,b),c);
        printf("%d\n",r);
    }
    return 0;
}
