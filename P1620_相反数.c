#include <stdio.h>

int main()
{
	int N,i,j;
	int arr[502];
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int count = 0;
	for (i = 0; i < N; i++)
	{
		for (j = i+1; j < N; j++)
		{
			if (arr[i] + arr[j] == 0)
			{
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}
