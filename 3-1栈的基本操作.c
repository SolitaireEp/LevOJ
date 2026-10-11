#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

char stack[MAXSIZE];
int top = 0;

void push(char c) {
    stack[top++] = c;
}

char pop() {
    --top;
        return stack[top];
}

int match(char left, char right) {
    return (left == '(' && right == ')')
        || (left == '[' && right == ']')
        || (left == '{' && right == '}');
}

int main()
{
    char s[MAXSIZE + 1];
    int i, len;
    scanf("%s", s);
    len = strlen(s);
    for (i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(s[i]);
        }
        else {
            if (top == 0) {
                printf("NO\n");
                return 0;
            }
            if (!match(pop(), s[i])) {
                printf("NO\n");
                return 0;
            }
        }
    }
    if (top == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
