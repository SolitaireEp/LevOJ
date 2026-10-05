#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int element;
    int next;
} Node;

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    int n = read();
    Node* nodes = (Node*)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        nodes[i].element = read();
        nodes[i].next = read();
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
        write(nodes[p].element);
        p = nodes[p].next;
    }
    putchar('\n');

    free(nodes);
    return 0;
}
