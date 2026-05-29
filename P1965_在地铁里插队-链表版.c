#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int id;
    struct Node* next;
} Node;
int main() {
    int n;
    scanf("%d", &n);

    int* mi = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &mi[i]);
    }
    Node** heads = (Node**)calloc(n + 1, sizeof(Node*));
    for (int i = 1; i <= n; i++) {
        Node* tail = NULL;
        for (int j = 0; j < mi[i]; j++) {
            int id;
            scanf("%d", &id);
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->id = id;
            newNode->next = NULL;
            if (heads[i] == NULL) {
                heads[i] = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int id, d;
        scanf("%d %d", &id, &d);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->id = id;
        newNode->next = heads[d];
        heads[d] = newNode;
    }
    for (int i = 1; i <= n; i++) {
        Node* p = heads[i];
        int first = 1;
        while (p != NULL) {
            if (first) {
                printf("%d", p->id);
                first = 0;
            }
            else {
                printf(" %d", p->id);
            }
            p = p->next;
        }
        printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        Node* p = heads[i];
        while (p != NULL) {
            Node* tmp = p;
            p = p->next;
            free(tmp);
        }
    }
    free(heads);
    free(mi);
    return 0;
}
