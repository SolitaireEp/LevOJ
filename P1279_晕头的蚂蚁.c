#include <stdio.h>
#include <stdlib.h>

int main()
{
    int L, n;
    scanf("%d %d", &L, &n);
    int min_time = 0, max_time = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        int left = x;
        int right = L - x;
        int min_i = left < right ? left : right;
        int max_i = left > right ? left : right;
        if (min_i > min_time) min_time = min_i;
        if (max_i > max_time) max_time = max_i;
    }
    printf("%d %d\n", min_time, max_time);
    return 0;
}
