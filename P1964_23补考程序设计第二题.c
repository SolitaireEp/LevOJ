#include<stdio.h>

int main()
{
	int n,i,j,t;
	int a[10][10], b[10][10], c[10][10]= {0};
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0 ; j < n; j++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++)
		for (j =i+1; j < n; j++)
		{
			t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &b[i][j]);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (t = 0; t < n; t++)
				c[i][j] += a[i][t] * b[t][j];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j != 0)
				printf(" ");
			printf("%d", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
