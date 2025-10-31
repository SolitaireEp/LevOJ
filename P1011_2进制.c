#include <stdio.h>
//递归法，相较比循环法简单
void Binary(int) 

int main() 
{
	int n;
	scanf("%d", &n);
	Binary(n);
	printf("\n");
	return 0;
}

void Binary(int n) 
{
	if (n > 1)
		Binary(n / 2);
	printf("%d", n % 2);
}
