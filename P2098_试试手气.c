#include <stdio.h>

int main()
{
	int a[6],n,i;
	scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);
	scanf("%d", &n);
	for (i = 0; i < 6; i++)
	{
		if(a[i]<(7-n))
			a[i]=7-n;
		else
			a[i] = 6 - n;
			
	}
	for(i=0;i<6;i++)
	{
		if (i != 5)
			printf("%d ", a[i]);
		else
			printf("%d\n", a[i]);
	}
	return 0;
}
