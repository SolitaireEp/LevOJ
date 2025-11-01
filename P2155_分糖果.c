#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int eat = 0,t;
	eat += a % 3;
	t=a/3;
	a = t;
	b += t;
	c += t;
	eat += b % 3;
	t = b/3;
	b = t;
	a += t;
	c += t;
	eat += c % 3;
	t = c/3;
	c = t;
	a += t;
	b += t;
	printf("%d %d %d\n", a, b, c);
	printf("%d\n", eat);
	return 0;
}
