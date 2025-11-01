#include <stdio.h>

int main()
{
    int n,k,i,j;
    int a[10001] = {0};
	scanf("%d %d", &n,&k);
    for(j=2;j<=k;j++)
    {
        for(i=j;i<=n;i=i+j)
        {
			a[i] = (a[i]==1?0:1);
		}
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            printf("%d\n",i);
        }
	}
    return 0;
}
