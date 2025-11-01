#include <stdio.h>
#include <math.h>

int isprime(int);

int main()
{
    int n,x,y;
	scanf("%d", &n);
    if (n % 2 == 0)
    {
        for (x = n-1;x>4; x-=2)
        {
                y = x-2;
                if (isprime(x) && isprime(y))
                {
                    printf("%d %d\n", y, x);
                    return 0;
                }
		}
    }
    else
    {
        for (x = n; x > 4; x -= 2)
        {
            y = x - 2;
            if (isprime(x) && isprime(y))
            {
                printf("%d %d\n", y, x);
                return 0;
            }
        }
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
    return 1;//此处为满足"return a value in all control paths"，同时题目条件已满足n>=5
}
