#include <stdio.h>

int main() {
    long long N;
    int b;
    scanf("%lld %d", &N, &b);

    int stack[100]; 
    int top = -1; 

    if (N == 0) {
        printf("0\n");
        return 0;
    }

    while (N > 0) {
        int rem = N % b;
        stack[++top] = rem;
        N /= b;
    }

    while (top >= 0) {
        int digit = stack[top--];
        if (digit < 10) {
            printf("%d", digit);
        }
        else {
            printf("%c", 'A' + digit - 10);
        }
    }
    printf("\n");
    return 0;
}
