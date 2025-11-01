#include <stdio.h>
#define N 100
void merge(int[], int[], int, int);

int main()
{
    int m,n,i,a[N],b[N];
    scanf("%d", &m); 
    scanf("%d", &n);
	for (i = 0; i < m; i++)
		scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
		scanf("%d", &b[i]);
	merge(a, b, m, n);
    return 0;
}

void merge(int a[], int b[], int m, int n)
{
    int i, j, t;
    for (i = 0; i < m - 1; i++)
        for (j = 0; j < m - 1 - i; j++)
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
    for(i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (b[j]>b[j + 1])
            {
                t = b[j];
                b[j] = b[j + 1];
                b[j + 1] = t;
			}
    i = 0;
    j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            printf("%d ", a[i++]);
        else
            printf("%d ", b[j++]);
    }
    while (i < m)
        printf("%d ", a[i++]);
    while (j < n)
        printf("%d ", b[j++]);
}
