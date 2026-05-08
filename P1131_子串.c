#include <stdio.h>
#include <string.h>

int sub(const char* str, const char* sub)
{
    return strstr(str, sub) != NULL;
    /*strstr 函数（声明在 <string.h>）
    原型：char *strstr(const char *haystack, const char *needle);
    功能：在 haystack（草堆）中寻找第一次出现 needle（针）的位置。
    返回值：
    如果 needle 是 haystack 的子串，返回指向该子串首字符的指针（非 NULL）；
    如果 needle 不是子串，返回 NULL；
    如果 needle 是空字符串，返回 haystack*/
}

void reverse(char* dest, const char* src, int len)
{
    for (int i = 0; i < len; i++)
        dest[i] = src[len - 1 - i];
    dest[len] = '\0';
}

int main()
{
    int n;
    char s[100][101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    int max_len = 0;
    int len0 = strlen(s[0]);
    for (int i = 0; i < len0; i++)
    {
        for (int j = i; j < len0; j++)
        {
            int L = j - i + 1;
            char x[101], rev[101];
            strncpy(x, s[0] + i, L);
            x[L] = '\0';
            reverse(rev, x, L);

            int ok = 1;
            for (int k = 1; k < n; k++)
            {
                if (!sub(s[k], x) && !sub(s[k], rev))
                {
                    ok = 0;
                    break;
                }
            }
            if (ok && L > max_len)
                max_len = L;
        }
    }
    printf("%d\n", max_len);
    return 0;
}
