#include <stdio.h>
#include <string.h>

#define DIGITS 500

void mul(const int *a, const int *b, int *c)
{
    int tmp[DIGITS * 2] = { 0 };
    for (int i = 0; i < DIGITS; ++i)
    {
        if (a[i] == 0)
            continue;
        for (int j = 0; j < DIGITS; ++j)
        {
            if (i + j >= DIGITS)
                break;
            tmp[i + j] += a[i] * b[j];
        }
    }
    int carry=0;
    for (int i=0;i<DIGITS;++i)
    {
        tmp[i] += carry;
        carry = tmp[i] / 10;
        c[i] = tmp[i] % 10;
    }
}
/* 2^n的二进制分解法：
初始化 res = 1，base = 2。
当 n > 0 时：
如果 n 是奇数，res = res * base。
不管奇偶，base = base * base（平方）。
n >>= 1（整除 2）。*/
void pow2(int n, int *res)
{
    int base[DIGITS] = {0};
    base[0] = 2;
    res[0] = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            int tmp[DIGITS];
            mul(res, base, tmp);
            memcpy(res,tmp,sizeof(int)*DIGITS);
        }
        int tmp[DIGITS];
        mul(base, base, tmp);
        memcpy(base, tmp, sizeof(int) * DIGITS);
		n >>= 1;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int ans[DIGITS] = {0};
    pow2(n,ans);
    int iszero = 1;
    for(int i=0;i<DIGITS;++i)
    {
        if (ans[i] != 0)
        {
            iszero = 0;
            break;
        }
    }
    if (iszero)
    {
        for (int i=0;i<DIGITS;++i)
            ans[i] = 9;
    }
    else
    {
        int i = 0;
        while (ans[i] == 0)
        {
            ans[9] = 9;
            ++i;
        }
        ans[i]--;
    }
    for (int i = DIGITS - 1; i >= 0; --i)
        printf("%d", ans[i]);
    printf("\n");
    return 0;
}
