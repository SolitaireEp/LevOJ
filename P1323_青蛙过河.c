#include <stdio.h>
int jump(int x)
{
	if (x > 2)
		return(jump(x - 1) + jump(x - 2));
	if (x == 1)
		return 2;
	if (x == 2)
		return 3;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", jump(n-1));
	return 0;
}
