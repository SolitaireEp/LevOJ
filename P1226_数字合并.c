#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    char* s1 = *(char**)a;
    char* s2 = *(char**)b;
    char tmp1[41], tmp2[41];
    strcpy(tmp1, s1);
    strcat(tmp1, s2);
    strcpy(tmp2, s2);
    strcat(tmp2, s1);
    return strcmp(tmp2, tmp1);
}
int main()
{
    int n;
    scanf("%d", &n);
    char nums[100][21];
    char* ptrs[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", nums[i]);
        ptrs[i] = nums[i];
    }
    qsort(ptrs, n, sizeof(char*), cmp);
    for (int i = 0; i < n; i++)
        printf("%s", ptrs[i]);
    printf("\n");
    return 0;
}
