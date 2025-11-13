#include <stdio.h>
#include <string.h>

char entire[1000010];
int startp[10005];

int main() 
{
    int n,m,i,cur=0;
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++)
	{
		int len;
		scanf("%d",&len);
		startp[i] = cur;
		scanf("%s", entire + cur);
		cur += len+1;
	}
	for(i=0;i<m;i++)
	{
		int q;
		scanf("%d", &q);
		printf("%s\n", entire + startp[q - 1]);
	}
    return 0;
}
