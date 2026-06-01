#include <stdio.h>
#include <string.h>

int main()
{
    char a[202], b[202], op;
    scanf("%s %s %c", a, b, &op);
    int am = a[strlen(a) - 1] - '0';
    int bm = b[strlen(b) - 1] - '0';
    if (op == '+')
        printf((am + bm) % 2 ? "ODD\n" : "EVEN\n");
    else
        printf((am * bm) % 2 ? "ODD\n" : "EVEN\n");
    return 0;
}
