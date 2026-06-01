#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int p = 0;
    for (int j = 0; j < m; j++)
    {
        int b;
        scanf("%d", &b);
        while (p < n && a[p] > b)
            p++;
        printf("%d\n", n - p);
    }
    return 0;
}
