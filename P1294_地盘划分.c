#include <stdio.h>

int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	long long count = 0;
	while (a && b)
	{
		if (a >= b)
		{
			count += a / b;
			a %= b;
		}
		else
		{
			count += b / a;
			b %= a;
		}
	}
	printf("%lld",count);
}
