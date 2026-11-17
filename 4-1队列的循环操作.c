#include <stdio.h>
#define MAXSIZE 10

int main()
{
    int queue[MAXSIZE], front = 0, rear = 0;
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        queue[rear] = x;
        rear = (rear + 1) % MAXSIZE;
    }
    while (front != rear) {
        printf("%d ", queue[front]);
        front = (front + 1) % MAXSIZE;
    }
    printf("\n");
    return 0;
}
