#include <stdio.h>

int main()
{
	double BMI,n, L;
	scanf("%lf %lf", &n,&L);
	BMI = n / (L * L);
	printf("%.1lf\n", BMI);
	if (BMI > 25)
	{
		printf("PANG\n");
	}
	else
	{
		printf("Hai Xing\n");
	}
	return 0;
}
