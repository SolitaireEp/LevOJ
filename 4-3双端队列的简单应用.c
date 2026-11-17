#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    long long q;
    scanf("%d %lld", &n, &q);

    long long* rem = (long long*)malloc(n * sizeof(long long));
    long long* finish = (long long*)malloc(n * sizeof(long long));
    int* queue = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &rem[i]);
        queue[i] = i;
    }

    int front = 0;
    int rear = n % (n + 1);
    long long now = 0;

    while (front != rear) {
        int id = queue[front];
        front = (front + 1) % (n + 1);

        if (rem[id] <= q) {
            now += rem[id];
            finish[id] = now;
        }
        else {
            rem[id] -= q;
            now += q;

            queue[rear] = id;
            rear = (rear + 1) % (n + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lld", finish[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    free(rem);
    free(finish);
    free(queue);
    return 0;
}
