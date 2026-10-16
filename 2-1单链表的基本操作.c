#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node, * LinkList;

int main()
{
    LinkList L, p, q;
    int n, i, j;
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    scanf("%d", &n);
    p = L;
    for (i = 0; i < n; i++) {
        q = (LinkList)malloc(sizeof(Node));
        scanf("%d", &q->data);
        
        //尾插法建立链表
        p->next = q;
        q->next = NULL;
        p = q;
        
    }
    scanf("%d", &j);
    p = L;
    
    //找到第j个结点的前驱
    for (i = 1; i < j; i++)
        p = p->next;

	//删除第j个结点
    q = p->next;
    p->next = q->next;
    free(q);
    
    p = L->next;
    
    //遍历输出
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}
