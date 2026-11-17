#include <stdio.h>
#include <string.h>

#define MAXSTRLEN 255

typedef unsigned char SString[MAXSTRLEN + 1];

void StrAssign(SString S, const char *str) {
    int len = (int)strlen(str);
    if (len > MAXSTRLEN) len = MAXSTRLEN;
    S[0] = (unsigned char)len;
    for (int i = 1; i <= len; i++) {
        S[i] = (unsigned char)str[i - 1];
    }
}

int StrLength(SString S) {
    return (int)S[0];
}

int StrCompare(SString S, SString T) {
    int i = 1;
    while (i <= S[0] && i <= T[0]) {
        if (S[i] != T[i]) {
            return (S[i] < T[i]) ? -1 : 1;
        }
        i++;
    }
    if (S[0] == T[0]) return 0;
    return (S[0] < T[0]) ? -1 : 1;
}

void Concat(SString T, SString S1, SString S2) {
    int len1 = S1[0];
    int len2 = S2[0];
    int total = len1 + len2;

    if (total <= MAXSTRLEN) {
        T[0] = (unsigned char)total;
        for (int i = 1; i <= len1; i++) {
            T[i] = S1[i];
        }
        for (int i = 1; i <= len2; i++) {
            T[len1 + i] = S2[i];
        }
    } else {
        T[0] = MAXSTRLEN;
        for (int i = 1; i <= len1; i++) {
            T[i] = S1[i];
        }
        for (int i = 1; i <= MAXSTRLEN - len1; i++) {
            T[len1 + i] = S2[i];
        }
    }
}

int main() {
    char buf[MAXSTRLEN + 10];
    SString S1, S2, T;

    scanf("%s", buf);
    StrAssign(S1, buf);

    scanf("%s", buf);
    StrAssign(S2, buf);

    printf("%d %d\n", StrLength(S1), StrLength(S2));

    printf("%d\n", StrCompare(S1, S2));

    Concat(T, S1, S2);
    for (int i = 1; i <= T[0]; i++) {
        putchar(T[i]);
    }
    putchar('\n');

    return 0;
}
