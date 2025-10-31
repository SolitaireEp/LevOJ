#include <stdio.h>
#include <math.h>

int main() 
{
	int a,b,c,d;
	double x, y,sum;
	scanf("%d %d %d %d",&a, &b, &c, &d);
	x = (double)a / b;
	y = (double)c / d;
	sum = 0.0001*round((x + y)*10000);
	printf("%.4lf\n",sum);
	return 0;
}
