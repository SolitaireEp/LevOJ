#include <stdio.h>
#include <string.h>

long long Btodec(int n, int base)
{
    char str[20];
    sprintf(str, "%d", n);
    long long val = 0;
    for (int i = 0; str[i]; i++)
    {
        int digit = str[i] - '0';
        if (digit >= base)
            return -1;
        val = val * base + digit;
    }
    return val;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int p, q, r;
        scanf("%d %d %d", &p, &q, &r);
        int found = 0;
        for (int B = 2; B <= 16; B++)
        {
            long long p_val = Btodec(p, B);
            if (p_val == -1) continue;
            long long q_val = Btodec(q, B);
            if (q_val == -1) continue;
            long long r_val = Btodec(r, B);
            if (r_val == -1) continue;
            if (p_val * q_val == r_val)
            {
                printf("%d\n", B);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("0\n");
    }
    return 0;
}
