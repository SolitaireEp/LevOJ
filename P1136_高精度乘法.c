#include <stdio.h>
#define MAX 3000

int main() {
    int n;
    scanf("%d", &n);
    char res[MAX];
    res[0] = '1';
    int len = 1;
    for (int i = 1; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < len; j++)
        {
            int digit = res[j] - '0';
            int product = digit * i + carry;
            res[j] = (product % 10) + '0';
            carry = product / 10;
        }
        while (carry)
        {
            res[len++] = (carry % 10) + '0';
            carry /= 10;
        }
    }
    for (int i = len - 1; i >= 0; i--)
        putchar(res[i]);
    putchar('\n');
    return 0;
}
