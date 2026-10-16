#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int element;
    int next;
} Node;

int main() {
    int n;
    scanf("%d", &n);

    Node* nodes = (Node*)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &nodes[i].element, &nodes[i].next);
    }

    int head = 0;

    int slow = head, fast = head;
    while (fast != -1 && nodes[fast].next != -1) {
        slow = nodes[slow].next;
        fast = nodes[nodes[fast].next].next;
    }

    int second = nodes[slow].next;
    nodes[slow].next = -1;

    int prev = -1, curr = second;
    while (curr != -1) {
        int next = nodes[curr].next;
        nodes[curr].next = prev;
        prev = curr;
        curr = next;
    }

    int p1 = head, p2 = prev;
    while (p1 != -1 && p2 != -1) {
        int p1_next = nodes[p1].next;
        int p2_next = nodes[p2].next;
        nodes[p1].next = p2;
        nodes[p2].next = p1_next;
        p1 = p1_next;
        p2 = p2_next;
    }

    int p = head;
    int first = 1;
    while (p != -1) {
        if (!first) putchar(' ');
        first = 0;
        printf("%d", nodes[p].element);
        p = nodes[p].next;
    }
    putchar('\n');

    free(nodes);
    return 0;
}
