#include <stdio.h>
#include <string.h>

#define MAX 1005

int numStack[MAX];
int numTop = -1;
char opStack[MAX];
int opTop = -1;

void pushNum(int x) {
    numStack[++numTop] = x;
}
int popNum() {
    return numStack[numTop--];
}

void pushOp(char op) {
    opStack[++opTop] = op;
}
char popOp() {
    return opStack[opTop--];
}
char peekOp() {
    return opStack[opTop];
}
int isOpEmpty() {
    return opTop == -1;
}

int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*') return 2;
    return 0;
}

void calc() {
    int b = popNum();
    int a = popNum();
    char op = popOp();
    int res = 0;
    switch (op) {
    case '+': res = a + b; break;
    case '-': res = a - b; break;
    case '*': res = a * b; break;
    }
    pushNum(res);
}

int main() {
    char s[MAX];
    scanf("%s", s);
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            pushNum(c - '0');
        }
        else if (c == '(') {
            pushOp(c);
        }
        else if (c == ')') {
            while (!isOpEmpty() && peekOp() != '(') {
                calc();
            }
            if (!isOpEmpty() && peekOp() == '(') {
                popOp();
            }
        }
        else {
            while (!isOpEmpty() && peekOp() != '(' &&
                getPriority(peekOp()) >= getPriority(c)) {
                calc();
            }
            pushOp(c);
        }
    }
    while (!isOpEmpty()) {
        calc();
    }
    printf("%d\n", popNum());
    return 0;
}
