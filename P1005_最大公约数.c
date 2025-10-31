#include<stdio.h>

int gcd(int,int)

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int a, b;
		scanf("%d %d",&a,&b);
		printf("%d\n", gcd(a,b));
	}
	return 0;
}

int gcd(int a, int b)
{
	do{
		int r = a % b;
		a = b;
		b = r;
	} while (b != 0);
	return a;
}
