#include <stdio.h>
#include <stdbool.h>

int n;
int h[10];
int ans[10]; 
bool used[10];

bool line(int pos)
{
    if (pos == n)
    {        
        for (int i = 0; i < n; i++)
        {
            if (i > 0) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
        return true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            if (pos > 0 && h[i] == h[ans[pos - 1]])
            {
                continue;
            }
            used[i] = true;
            ans[pos] = i;
            if (line(pos + 1))
            {
                return true;
            }
            used[i] = false;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    line(0);
    return 0;
}
