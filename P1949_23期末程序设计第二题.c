#include<stdio.h>
#include <math.h>
//P1051_绝对素数排序版，加了个数组和冒泡排序
int isprime(int);
int opp(int);

int main()
{
	int n,i=0,j,g;
	int a[100] = { 0 };
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		int y = opp(x);
		if (isprime(x) && isprime(y))
		{
			a[i++] = x;
		}
	}
	g = i;
	for (i = 0; i < g; i++)
		for (j = 0; j < g - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	for (i = 0; i < g; i++)
		printf("%d\n", a[i]);
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
