#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    int max = 0,cur = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (abs(a) <= 100) {
            cur++;
            if (cur > max)
                max = cur;
        }
        else
            cur = 0;
    }
    printf("%d\n", max);
    return 0;
}
