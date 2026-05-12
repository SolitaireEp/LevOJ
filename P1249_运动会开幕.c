#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    int people;
    char continent[50];
} Country;

int cmp(const void* a, const void* b)
{
    Country* c1 = (Country*)a;
    Country* c2 = (Country*)b;
    return strcmp(c1->name, c2->name);
}

int main()
{
    int n;
    scanf("%d", &n);
    Country* countries = (Country*)malloc(n * sizeof(Country));
    Country china;
    int china_pos = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %d %s", &countries[i].id, countries[i].name,
            &countries[i].people, countries[i].continent);
        if (strcmp(countries[i].name, "China") == 0)
        {
            china = countries[i];
            china_pos = i;
        }
    }
    Country* others = (Country*)malloc((n - 1) * sizeof(Country));
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != china_pos)
            others[j++] = countries[i];
    }
    qsort(others, n - 1, sizeof(Country), cmp);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d %s %d %s\n", others[i].id, others[i].name,
            others[i].people, others[i].continent);
    }
    printf("%d %s %d %s\n", china.id, china.name, china.people, china.continent);
    free(countries);
    free(others);
    return 0;
}
