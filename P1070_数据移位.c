#include <stdio.h>

#define N 1000

int main()
{
    int k,i,t,n,a[N];
    scanf("%d", &n); 
    scanf("%d", &k);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
    while(k--)
    {
        t = a[0];
        for(i = 0; i < n; i++)
            a[i] = a[i+1];
        a[n-1] = t;
	}
    for(i = 0; i < n; i++)
		printf("%d\n", a[i]);
    return 0;
}
