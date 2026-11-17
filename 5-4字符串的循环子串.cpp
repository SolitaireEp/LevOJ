#include <stdio.h>
#include <string.h>

#define MAXN 1000005

char s[MAXN];
int pi[MAXN];

int main() {
    if (scanf("%s", s) != 1)
        return 0;
    int n = (int)strlen(s);
    if (n <= 1) {
        printf("1\n");
        return 0;
    }
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    int max_border = pi[n - 1];
    int cycle_len = n - max_border;
    if (n % cycle_len == 0)
        printf("%d\n", n / cycle_len);
    else
        printf("1\n");
    return 0;
}
