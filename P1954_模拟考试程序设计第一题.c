#include<stdio.h>
#include<string.h>
struct rec
{
	int e1, e2, e3, e4;
	int area;
}input[1000], output[1000];
int fun(struct rec a[], struct rec b[], int n)
{
	/*****************开始***********************/
	int i, j, num = 0;
	struct rec temp;
	for (i = 0; i < n; i++)
	{
		if (a[i].e1 == a[i].e2 && a[i].e2 == a[i].e3 && a[i].e3 == a[i].e4)
		{
			b[num].area = a[i].e1 * a[i].e1;
			num++;
		}
	}
	for (i = 0; i < num; i++)
		for (j = 0; j < num - i - 1; j++)
			if (b[j].area > b[j + 1].area)
			{
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
	return num;
	/*****************结束**********************/
}
int main()
{
	int N, i, num;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d%d%d%d", &input[i].e1,&input[i].e2, &input[i].e3,&input[i].e4);
	num = fun(input, output, N);
	for (i = 0; i < num; i++)
		printf("%d\n", output[i].area);
	return 0;
}

