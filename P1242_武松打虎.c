#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    return (x > y) - (x < y);
}

int main()
{
    int n;
    long long t;
    scanf("%d %lld", &n, &t);
    long long* a = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long), cmp);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (t >= a[i])
        {
            t -= a[i];
            cnt++;
        }
        else
            break;
    }
    printf("%d\n", cnt);
    free(a);
    return 0;
}
