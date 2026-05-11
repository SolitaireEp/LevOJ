#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int a, b;
} Score;

void simulate(const char *s, int target, Score **results, int *cnt)
{
    int cap = 100;
    Score *res = malloc(cap * sizeof(Score));
    int idx = 0;
    int a = 0, b = 0;

    for (const char *p = s; *p; ++p)
    {
        if (*p == ' ') continue;
        if (*p == 'E') break;
        if (*p == 'W') a++;
        else if (*p == 'L')
          b++;
        if ((a >= target || b >= target) && abs(a - b) >= 2)
        {
            res[idx].a = a;
            res[idx].b = b;
            idx++;
            if (idx == cap)
            {
                cap *= 2;
                res = realloc(res, cap * sizeof(Score));
            }
            a = b = 0;
        }
    }
    if (a != 0 || b != 0)
    {
        res[idx].a = a;
        res[idx].b = b;
        idx++;
    }
    *results = res;
    *cnt = idx;
}
int main() {
    char s[1000005];
    fgets(s, sizeof(s), stdin);
    // 去掉末尾换行符
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') s[len-1] = '\0';
    Score *res11, *res21;
    int cnt11, cnt21;
    simulate(s, 11, &res11, &cnt11);
    simulate(s, 21, &res21, &cnt21);
    for (int i = 0; i < cnt11; ++i)
        printf("%d:%d\n", res11[i].a, res11[i].b);
    printf("\n");
    for (int i = 0; i < cnt21; ++i)
        printf("%d:%d\n", res21[i].a, res21[i].b);
    free(res11);
    free(res21);
    return 0;
}
