//原始 O(n²) 逐位乘法
#include <stdio.h>
#include <string.h>
#define MAX 10000

void reverse(char* s)
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
    {
        char t = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = t;
    }
}

int add(char* res, const char* a, const char* b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;
    int carry = 0;
    int i;
    for (i = 0; i < max_len; i++) {
        int da = i < len_a ? a[i] - '0' : 0;
        int db = i < len_b ? b[i] - '0' : 0;
        int sum = da + db + carry;
        res[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry)
        res[i++] = carry + '0';
    res[i] = '\0';
    return i;
}

int main()
{
    char a[MAX], b[MAX];
    scanf("%s %s", a, b);
    reverse(a);
    reverse(b);
    char ans[MAX] = "0";
    int len_b = strlen(b);
    int len_a = strlen(a);
    for (int i = 0; i < len_b; i++)
    {
        int multiplier = b[i] - '0';
        if (multiplier == 0)
            continue;
        char c[MAX];
        int carry = 0;
        int k;
        for (k = 0; k < len_a; k++)
        {
            int product = (a[k] - '0') * multiplier + carry;
            c[k] = (product % 10) + '0';
            carry = product / 10;
        }
        while (carry)
        {
            c[k++] = (carry % 10) + '0';
            carry /= 10;
        }
        c[k] = '\0';
        if (i > 0)
        {
            for (int j = k - 1; j >= 0; j--)
                c[j + i] = c[j];
            for (int j = 0; j < i; j++)
                c[j] = '0';
            k += i;
            c[k] = '\0';
        }
        char tmp[MAX];
        add(tmp, ans, c);
        strcpy(ans, tmp);
    }
    reverse(ans);
    printf("%s\n", ans);
    return 0;
}


//万进制
//输入数字字符串后，从低位向高位每 4 位一组存入数组（注意数组元素存储 0–9999）。
//乘法时，两个数组元素的乘积可能达到 9999×9999 ≈ 1e8，加上进位后仍需用 64 位整数（long long）暂存，避免溢出。
//最后输出时，每个元素转换为固定 4 位十进制（除最高位外不足 4 位的前补零）。
/*
#include <stdio.h>
#include <string.h>
#define BASE 10000
#define MAX_LEN 100   // 最大元素个数（200 位 -> 50 个元素）
// 大整数结构
typedef struct {
    int len;          // 元素个数
    int d[MAX_LEN];   // 低位在前（d[0] 是个位对应 0–9999）
} BigNum;
// 字符串转万进制
void str_to_big(const char *s, BigNum *num) {
    int slen = strlen(s);
    num->len = (slen + 3) / 4;
    for (int i = 0; i < num->len; i++) {
        int val = 0;
        int start = slen - 4 * (i + 1);
        if (start < 0) start = 0;
        for (int j = start; j < slen - 4 * i; j++) {
            val = val * 10 + (s[j] - '0');
        }
        num->d[i] = val;
    }
}
// 万进制乘法（大数 * 大数）
void mul_big(const BigNum *a, const BigNum *b, BigNum *c) {
    int i, j;
    long long tmp[MAX_LEN * 2] = {0};   // 暂存中间结果
    for (i = 0; i < a->len; i++) {
        for (j = 0; j < b->len; j++) {
            tmp[i + j] += (long long)a->d[i] * b->d[j];
        }
    }
    // 处理进位
    int carry = 0;
    for (i = 0; i < a->len + b->len; i++) {
        long long sum = tmp[i] + carry;
        c->d[i] = sum % BASE;
        carry = (int)(sum / BASE);
    }
    c->len = a->len + b->len;
    while (c->len > 1 && c->d[c->len - 1] == 0) c->len--;
}
// 输出万进制大整数
void print_big(const BigNum *num) {
    // 最高位直接输出
    printf("%d", num->d[num->len - 1]);
    for (int i = num->len - 2; i >= 0; i--) {
        printf("%04d", num->d[i]);   // 补零至 4 位
    }
    printf("\n");
}
int main() {
    char str1[MAX_LEN * 4 + 1], str2[MAX_LEN * 4 + 1];
    BigNum num1, num2, result;
    // 输入两个大整数
    scanf("%s", str1);
    scanf("%s", str2);
    // 转换为万进制大整数
    str_to_big(str1, &num1);
    str_to_big(str2, &num2);
    // 计算乘积
    mul_big(&num1, &num2, &result);
    // 输出结果
    print_big(&result);
    return 0;
}
*/


//分治法（Karatsuba 算法），将两个大整数各分成高低两段，利用公式减少乘法次数。当数字长度较大（例如数千位）时，Karatsuba 明显更快于原始算法。
//快速傅里叶变换（FFT）加速,将大整数看作多项式，利用 FFT 进行多项式乘法，复杂度 O(n log n)。适用于上万位的乘法。
