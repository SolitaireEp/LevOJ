#include <stdio.h>
#include <string.h>

#define MAXN 10005

int main()
{
    int N, M;
    int Q[MAXN];
    int front = 0, rear = 0;
    scanf("%d%d", &N, &M);
    while (M--) {
        char op[20];
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            int x;
            scanf("%d", &x);
            if ((rear + 1) % N == front) {
                printf("Full\n");
            } else {
                Q[rear] = x;
                rear = (rear + 1) % N;
                printf("%d\n", rear);
            }
        } else if (strcmp(op, "dequeue") == 0) {
            if (front == rear) {
                printf("Empty\n");
            } else {
                int x = Q[front];
                front = (front + 1) % N;
                printf("%d %d\n", x, front);
            }
        } else if (strcmp(op, "query") == 0) {
            int len = (rear - front + N) % N;
            printf("%d\n", len);
        }
    }
    return 0;
}
