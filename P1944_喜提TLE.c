#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k;
    scanf("%d %d", &n, &m);
    char **str = malloc((n + 1) * sizeof(char *));
    int* x = malloc((n + 1) * sizeof(int));
    for (i = 1; i <= n; ++i)
    {
        str[i] = malloc(20001);
        scanf("%20001s", str[i]);
        x[i] = i;
    }
    for (k = 1; k <= m; ++k)
    {
        scanf("%d %d", &i, &j);
            int t = x[i]; 
            x[i] = x[j]; 
            x[j] = t;
    }
    for (k = 1; k <= n; ++k)
        printf("%s\n", str[x[k]]);
    for (i = 1; i <= n; ++i)
        free(str[i]);
    free(str);
    free(x);
    return 0;
}
