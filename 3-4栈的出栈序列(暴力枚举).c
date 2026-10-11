#include <stdio.h>
#include <stdlib.h>

int n;
int in[10];
int ans[1000];
int cnt = 0;

void dfs(int pos, int top, int stack[], int out[], int outLen) {
    if (outLen == n) {
        int num = 0;
        for (int i = 0; i < n; i++) {
            num = num * 10 + out[i];
        }
        ans[cnt++] = num;
        return;
    }

    if (pos < n) {
        int new_stack[10];
        for (int i = 0; i < top; i++) new_stack[i] = stack[i];
        new_stack[top] = in[pos];
        dfs(pos + 1, top + 1, new_stack, out, outLen);
    }

    if (top > 0) {
        int new_out[10];
        for (int i = 0; i < outLen; i++) new_out[i] = out[i];
        new_out[outLen] = stack[top - 1];

        int new_stack[10];
        for (int i = 0; i < top - 1; i++) new_stack[i] = stack[i];
        dfs(pos, top - 1, new_stack, new_out, outLen + 1);
    }
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    int stack[10] = { 0 };
    int out[10] = { 0 };
    dfs(0, 0, stack, out, 0);
    qsort(ans, cnt, sizeof(int), cmp);
    for (int i = 0; i < cnt; i++) {
        int x = ans[i];
        int digits[10];
        for (int j = n - 1; j >= 0; j--) {
            digits[j] = x % 10;
            x /= 10;
        }
        for (int j = 0; j < n; j++) {
            if (j > 0) printf(" ");
            printf("%d", digits[j]);
        }
        printf("\n");
    }
    return 0;
}
