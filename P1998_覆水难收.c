#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    scanf("%d %d", &n, &m);
    int a[50][50];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    long long smax = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            long long cross = a[i][j];
            for (k = 1; k <= m; k++)
            {
                if (i - k >= 0)
                    cross += a[i - k][j];
                else
                    break;
            }
            for (k = 1; k <= m; k++)
            {
                if (i + k < n)
                    cross += a[i + k][j];
                else
                    break;
            }
            for (k = 1; k <= m; k++)
            {
                if (j - k >= 0)
                    cross += a[i][j - k];
                else
                    break;
            }
            for (int k = 1; k <= m; k++)
            {
                if (j + k < n)
                    cross += a[i][j + k];
                else
                    break;
            }
            if (cross > smax)
                smax = cross;
            long long diag = a[i][j];
            for (int k = 1; k <= m; k++)
            {
                if (i - k >= 0 && j - k >= 0)
                    diag += a[i - k][j - k];
                else
                    break;
            }
            for (int k = 1; k <= m; k++)
            {
                if (i - k >= 0 && j + k < n)
                    diag += a[i - k][j + k];
                else
                    break;
            }
            for (int k = 1; k <= m; k++)
            {
                if (i + k < n && j - k >= 0)
                    diag += a[i + k][j - k];
                else
                    break;
            }
            for (int k = 1; k <= m; k++)
            {
                if (i + k < n && j + k < n)
                    diag += a[i + k][j + k];
                else
                    break;
            }
            if (diag > smax)
                smax = diag;
        }
    }
    printf("%lld\n", smax);
    return 0;
}
