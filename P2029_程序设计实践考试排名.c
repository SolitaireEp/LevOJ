#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int id;
    struct Node* next;
} Node;

typedef struct 
{
    Node* head;
}Bucket;

int main() 
{
    int M, N;
    scanf("%d %d", &M, &N);
    Bucket* count = (Bucket*)calloc(M + 1, sizeof(Bucket));
    for (int i = 0; i <= M; i++) 
        count[i].head = NULL;
    for (int i = 0; i < N; i++)
    {
        int X, Y;
        scanf("%d %d", &X, &Y);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->id = X;
        newNode->next = NULL;
        if (count[Y].head == NULL)
            count[Y].head = newNode;
        else 
        {
            Node* current = count[Y].head;
            while (current->next != NULL)
                current = current->next;
            current->next = newNode;
        }
    }
    for (int i = M; i >= 0; i--)
    {
        printf("%d", i);
        Node* current = count[i].head;
        while (current != NULL)
        {
            printf(" %d", current->id);
            current = current->next;
        }
        printf("\n");
    }
    for (int i = 0; i <= M; i++) 
    {
        Node* current = count[i].head;
        while (current != NULL)
        {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(count);
    return 0;
}
