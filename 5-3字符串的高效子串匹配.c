#include <stdio.h>
#include <string.h>

#define MAXN 100005

char s[MAXN], t[MAXN];
int pi[MAXN];

int main(){
    if (scanf("%s", s) != 1)
        return 0;
    if (scanf("%s", t) != 1)
        return 0;
    int n = (int)strlen(s);
    int m = (int)strlen(t);
    if (m == 0) {
        printf("0\n");
        return 0;
    }
    pi[0] = 0;
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && t[i] != t[j])
            j = pi[j - 1];
        if (t[i] == t[j])
            j++;
        pi[i] = j;
    }

    int j = 0;
    int found = 0;
    int first = 1;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != t[j])
            j = pi[j - 1];
        if (s[i] == t[j]) 
            j++;
        if (j == m) {
            int start = i - m + 2;
            if (!first)
                putchar(' ');
            printf("%d", start);
            first = 0;
            found = 1;
            j = pi[j - 1];
        }
    }
    if (!found)
        printf("0");
    printf("\n");
    return 0;
}
