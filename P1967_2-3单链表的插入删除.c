#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Node* prev;
    struct Node* next;
} Node;

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL, * tail = NULL, * cur = NULL;

    for (int k = 0; k < n; k++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            if (cur != NULL) {
                cur = cur->next;
            }
        }
        else if (op == 2) {
            int x;
            scanf("%d", &x);
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->id = x;

            if (cur != NULL) {
                newNode->prev = cur->prev;
                newNode->next = cur;
                if (cur->prev != NULL) {
                    cur->prev->next = newNode;
                }
                else {
                    head = newNode;
                }
                cur->prev = newNode;
                cur = newNode; 
            }
            else {
                newNode->next = NULL;
                newNode->prev = tail;
                if (tail != NULL) {
                    tail->next = newNode;
                }
                else {
                    head = newNode;
                }
                tail = newNode;
                cur = newNode;
            }
        }
        else if (op == 3) {
            if (cur != NULL) {
                Node* del = cur;
                Node* nextNode = cur->next;

                if (del->prev != NULL) {
                    del->prev->next = del->next;
                }
                else {
                    head = del->next;
                }
                if (del->next != NULL) {
                    del->next->prev = del->prev;
                }
                else {
                    tail = del->prev;
                }
                free(del);
                cur = nextNode;
            }
        }
    }

    Node* p = head;
    int first = 1;
    while (p != NULL) {
        if (!first) {
            printf(" ");
        }
        first = 0;
        printf("%d", p->id);
        p = p->next;
    }
    printf("\n");

    p = head;
    while (p != NULL) {
        Node* tmp = p;
        p = p->next;
        free(tmp);
    }

    return 0;
}
