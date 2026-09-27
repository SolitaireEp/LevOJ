#include <stdio.h>
#define MAXSIZE 200

int main()
{
    int a[MAXSIZE], n, i, j, e;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d%d", &i, &e);
    for (j = n - 1; j > i - 1; j--)
        a[j + 1] = a[j];
    a[i - 1] = e;
    n++;
    scanf("%d", &j);
    for (i = j - 1; i < n; i++)
        a[i] = a[i + 1];
    for (i = 0; i < n - 1; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
