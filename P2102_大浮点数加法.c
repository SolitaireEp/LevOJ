#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void trim_leading_zeros(char* s) {
    int len = strlen(s);
    int i = 0;
    while (i < len && s[i] == '0') i++;
    if (i == len) {
        s[0] = '0';
        s[1] = '\0';
    }
    else {
        memmove(s, s + i, len - i + 1);
    }
}

void trim_trailing_zeros(char* s) {
    int len = strlen(s);
    int i = len - 1;
    while (i >= 0 && s[i] == '0') i--;
    if (i < 0) {
        s[0] = '0';
        s[1] = '\0';
    }
    else {
        s[i + 1] = '\0';
    }
}

void reverse(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}

int main() {
    char a[500], b[500];
    char int_a[300], frac_a[300];
    char int_b[300], frac_b[300];
    scanf("%s", a);
    scanf("%s", b);
    char* dot = strchr(a, '.');
    int pos_a = dot - a;
    strncpy(int_a, a, pos_a);
    int_a[pos_a] = '\0';
    strcpy(frac_a, a + pos_a + 1);
    dot = strchr(b, '.');
    int pos_b = dot - b;
    strncpy(int_b, b, pos_b);
    int_b[pos_b] = '\0';
    strcpy(frac_b, b + pos_b + 1);
    trim_leading_zeros(int_a);
    trim_leading_zeros(int_b);
    int len_frac_a = strlen(frac_a);
    int len_frac_b = strlen(frac_b);
    int max_frac_len = len_frac_a > len_frac_b ? len_frac_a : len_frac_b;
    char frac_a_padded[300], frac_b_padded[300];
    strcpy(frac_a_padded, frac_a);
    for (int i = len_frac_a; i < max_frac_len; i++) frac_a_padded[i] = '0';
    frac_a_padded[max_frac_len] = '\0';
    strcpy(frac_b_padded, frac_b);
    for (int i = len_frac_b; i < max_frac_len; i++) frac_b_padded[i] = '0';
    frac_b_padded[max_frac_len] = '\0';
    char frac_res[300];
    int carry = 0;
    for (int i = max_frac_len - 1; i >= 0; i--) {
        int sum = (frac_a_padded[i] - '0') + (frac_b_padded[i] - '0') + carry;
        frac_res[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    frac_res[max_frac_len] = '\0';
    trim_trailing_zeros(frac_res);
    char int_a_rev[300], int_b_rev[300];
    strcpy(int_a_rev, int_a);
    strcpy(int_b_rev, int_b);
    reverse(int_a_rev);
    reverse(int_b_rev);
    int len_int_a = strlen(int_a_rev);
    int len_int_b = strlen(int_b_rev);
    int max_int_len = len_int_a > len_int_b ? len_int_a : len_int_b;
    char int_res_rev[300];
    int idx = 0;
    for (int i = 0; i < max_int_len; i++) {
        int digit_a = (i < len_int_a) ? (int_a_rev[i] - '0') : 0;
        int digit_b = (i < len_int_b) ? (int_b_rev[i] - '0') : 0;
        int sum = digit_a + digit_b + carry;
        int_res_rev[idx++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry) {
        int_res_rev[idx++] = carry + '0';
    }
    int_res_rev[idx] = '\0';
    reverse(int_res_rev);
    trim_leading_zeros(int_res_rev);
    printf("%s.%s\n", int_res_rev, frac_res);
    return 0;
}
