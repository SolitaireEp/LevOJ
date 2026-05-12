#include <stdio.h>
#include <string.h>

int main()
{
    char str[20], substr[4];
    scanf("%s %s", str, substr);
    int len = strlen(str);
    int maxpos = 0;
    for (int i = 1; i < len; i++)
    {
        if (str[i] > str[maxpos])
            maxpos = i;
    }
    for (int i = 0; i <= maxpos; i++)
        putchar(str[i]);
    printf("%s", substr);
    for (int i = maxpos + 1; i < len; i++)
        putchar(str[i]);
    putchar('\n');
    return 0;
}
