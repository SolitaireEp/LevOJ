#include <stdio.h>

int main()
{
    int n, k,m=0;
    scanf("%d", &n); 
    k = n;
    while (k != 0)
    {
		m = m * 10 + k % 10;
		k = k / 10;
    }
    if(n == m)
        printf("yes\n");
    else
		printf("no\n");
    return 0;
}
