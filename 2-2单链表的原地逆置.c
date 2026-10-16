#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int element;
	int next;
} Node;

int main() {
	int n,i;
	scanf("%d", &n);
	
	Node* nodes = (Node*)malloc(n * sizeof(Node));
	for (i = 0; i < n; i++) {
		scanf("%d %d", &nodes[i].element, &nodes[i].next);
	}

	int newh = -1;
	int cur = 0;
	while (cur != -1) {
		int next = nodes[cur].next;
		nodes[cur].next = newh;
		newh = cur;
		cur = next;
	}
	printf("%d\n", newh);
	for (i = 0; i < n; i++) {
		printf("%d %d\n", nodes[i].element, nodes[i].next);
	}

	free(nodes);
	return 0;
}
