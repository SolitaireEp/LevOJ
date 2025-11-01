#include <stdio.h>

#define N 10000

int main()
{
    int T,a[N],x,i;
	scanf("%d", &T);
    while (T--)
    {
        int n = 0, min = 100, max = 0;
        double avg = 0;
        for (i = 1; i < 1000; i++)
        {
		    scanf("%d", &x);
            if(x!=-1)
            {
                a[i]=x;
                avg+=x;
				if (x < min) min = x;
				if (x > max) max = x;
                n++;
            }
            else
                break;
        }
        avg=avg/n;
		printf("%d\n",n);
        printf("%d\n",max);
        printf("%d\n",min);
        printf("%.1lf\n",avg);
    }
    return 0;
}
