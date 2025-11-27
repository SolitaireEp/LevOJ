#include <stdio.h>
#include <math.h>
//和luogu那个“旗鼓相当的对手”一样可以结构体做
int main()
{
	int N, t, a[1001][4]={0}, i, j, k;
	char name[1001][9];
	scanf("%d",&N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", name[i]);
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &t);
			a[i][j] = t;
			a[i][3] += t;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (k = i + 1; k < N; k++)
		{
			if (abs(a[i][3] - a[k][3]) > 10)
				continue;
			for (j = 0; j < 3; j++)
				if (abs(a[i][j] - a[k][j]) > 5)
				{
					j = 0;
					break;
				}
			if (j == 3)
				printf("%s %s\n", name[i], name[k]);
		}
	}
	return 0;
}
