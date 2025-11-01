#include <stdio.h>

int main()
{
	int n, a, b, c;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a + b <= c || a + c <= b || b + c <= a)
			printf("Not Triangle\n");
		else if (a == b && b == c)
			printf("Regular Triangle\n");
		else if (a == b || b == c || a == c)
			printf("Isosceles Triangle\n");
		else
			printf("Triangle\n");
	}
	return 0;
}
