#include<stdio.h>

int main()
{
	unsigned int m, n, a, b;
	int found=0;
	scanf("%u %u", &m, &n);
	for (b = 0; b <= m; b++)
	{
		a = m - b;
		if (2 * a + 4 * b == n)
		{
			printf("%u %u\n", a, b);
			found = 1;
			break;
		}
	}
	if (!found)//if((b==m)&&(2 * a + 4 * b != n))WA,可改为"b==m+1"
		printf("-1 -1\n");
	return 0;
}
