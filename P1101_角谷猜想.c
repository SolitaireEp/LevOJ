#include <stdio.h>

int f(int);

int main()
{
    int T;
	scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
		printf("%d\n", f(n));
    }
    return 0;
}

int f(int x)
{
	int step = 0;
    while (x != 1)
    {
        if (x % 2 == 0)
        {
            x /= 2;
            step++;
        }
        else
        {
			x = (3 * x + 1)/2;
			step++;
        }
	}
    return step;
}
