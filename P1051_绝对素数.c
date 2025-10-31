#include<stdio.h>
#include <math.h>

int isprime(int);
int opp(int);

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		int y = opp(x);
		if (isprime(x) && isprime(y))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}

int isprime(int a)
{
	int i;
	for (i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
			return 0;
	}
	if (i >= sqrt(a))
		return 1;
}

int opp(int a)
{
	int t = 0;
	int sum = 0;
	for (; a; a = a / 10)
	{
		t = a % 10;
		sum = sum * 10 + t;
	}
	return sum;
}
