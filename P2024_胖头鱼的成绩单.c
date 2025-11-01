#include <stdio.h>

int main()
{
	int K,i,j,t;
	scanf("%d", &K);
	int a[31] = {0};
	for (i = 0; i < K; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < K - 1; i++)
		for (j = 0; j < K - 1 - i; j++)
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
	for (i = K - 1; i >= 0; i--)
	{
		if (a[i] >= 70)
			printf("%d\n", a[i]);
	}
	return 0;
}
