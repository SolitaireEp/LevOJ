#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int* data;
	int size;
	int capacity;
}Vector;

//初始化
void initVec(Vector* v, int cap) {
	v->data = (int *)malloc(cap * sizeof(int));
	if(v->data==NULL)
		exit(1);
	v->size = 0;
	v->capacity = cap;
}

//扩容
void expand(Vector* v) {
	int i;
	int newcap = v->capacity * 2;
	int *newdata = (int*)malloc(newcap * sizeof(int));
	if(newdata==NULL)
		exit(1);
	for (i = 0; i < v->size; i++) {
		newdata[i] = v->data[i];
	}
	free(v->data);
	v->data = newdata;
	v->capacity = newcap;
}

//末尾添加
void pushback(Vector* v, int x) {
	v->data[v->size] = x;
	v->size++;
	if (v->size == v->capacity) {
		expand(v);
	}
}

//释放内存
void destroyVec(Vector* v) {
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}

int main()
{
    int q, n , op, p, x;
	scanf("%d %d", &q, &n);
	Vector v;
	initVec(&v, n);
	while (q--) {
		scanf("%d", &op);
		switch (op) {
		case 1:
			scanf("%d", &x);
			pushback(&v, x);
			break;
		case 2:
			scanf("%d%d", &p, &x);
			v.data[p] = x;
			break;
		case 3:
			scanf("%d", &p);
			printf("%d\n", v.data[p]);
			break;
		case 4:
			printf("%d\n", v.size);
			break;
		case 5:
			printf("%d\n", v.capacity);
			break;
		}
	}
	destroyVec(&v);
    return 0;
}
