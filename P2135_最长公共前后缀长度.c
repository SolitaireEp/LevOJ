#include <stdio.h>
#include <string.h>
int main() {
    char a[101], b[101];
    scanf("%s %s", a, b);
    int i = 0, la = strlen(a), lb = strlen(b);
    while (i < la && i < lb && a[i] == b[i]) i++;
    int j = 0;
    while (j < la && j < lb && a[la - j - 1] == b[lb - j - 1]) j++;
    printf("%d %d", i, j);
}
