#include <stdio.h>
#include <string.h>

int main()
{
	int N, M, Q;
	scanf("%d %d %d", &N, &M, &Q);
	int a[N][M];
	memset(a, 0, sizeof(a));
	while (Q--)
	{
		int T, C;
		scanf("%d %d", &T, &C);
		if (T == 0)
		{
			for (int j = 0; j < M; j++)
			{
				a[C - 1][j] = 1;
			}
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				a[i][C - 1] = 1;
			}
		}
	}
	int safe = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == 0)
			{
				safe++;
			}
		}
	}
	printf("%d", safe);
	return 0;
}
