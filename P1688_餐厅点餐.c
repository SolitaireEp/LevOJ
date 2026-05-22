#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d, e;
    int min, max;
    int count;
    int s1, s2, s3, s4, s5;
    int sum, sum1, sum2, sum3, sum4;
    int i, j;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    int* aMenu = (int*)malloc(a * sizeof(int));
    for (i = 0; i < a; i++) scanf("%d", &aMenu[i]);
    int* bMenu = (int*)malloc(b * sizeof(int));
    for (i = 0; i < b; i++) scanf("%d", &bMenu[i]);
    int* cMenu = (int*)malloc(c * sizeof(int));
    for (i = 0; i < c; i++) scanf("%d", &cMenu[i]);
    int* dMenu = (int*)malloc(d * sizeof(int));
    for (i = 0; i < d; i++) scanf("%d", &dMenu[i]);
    int* eMenu = (int*)malloc(e * sizeof(int));
    for (i = 0; i < e; i++) scanf("%d", &eMenu[i]);
    scanf("%d %d", &min, &max);
    count = 0;
    for (s4 = 0; s4 < d; s4++)
    {
        for (i = s4; i < d; i++)
        {
            if (i == s4)
                sum1 = dMenu[s4];
            else
                sum1 = dMenu[s4] + dMenu[i];

            for (s5 = 0; s5 < e; s5++)
            {
                for (j = s5; j < e; j++)
                {
                    if (j == s5)
                        sum2 = eMenu[s5];
                    else
                        sum2 = eMenu[s5] + eMenu[j];
                    for (s2 = 0; s2 < b; s2++)
                    {
                        for (s1 = 0; s1 < a; s1++)
                        {
                            sum3 = bMenu[s2] + aMenu[s1];
                            sum = sum1 + sum2 + sum3;
                            if (sum >= min && sum <= max)
                                count++;
                        }
                    }

                    for (s3 = 0; s3 < c; s3++)
                    {
                        sum4 = cMenu[s3];
                        sum = sum1 + sum2 + sum4;
                        if (sum >= min && sum <= max)
                            count++;
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    free(aMenu);
    free(bMenu);
    free(cMenu);
    free(dMenu);
    free(eMenu);
    return 0;
}
