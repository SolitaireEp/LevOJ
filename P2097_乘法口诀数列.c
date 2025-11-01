#include <stdio.h>

int main()
{
	int a1,a2,n;
	scanf("%d %d %d", &a1,&a2,&n);
	int ar[15];
	ar[0] = a1;
	ar[1] = a2;
	int j;
	int i = 2;
	for (j = 2; j < n; j++)
	{
		int t = ar[j - 2] * ar[j - 1];
		if (t < 10)
		{
			ar[i] = t;
			i++;
		}
		else
		{
			ar[i] = t / 10;
			i++;
			ar[i] = t % 10;
			i++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			printf(" ");
		printf("%d", ar[i]);
	}
	return 0;
}
