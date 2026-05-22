#include <stdio.h>

int main()
{
    int M, V1, V2, T1, T2;
    scanf("%d %d %d %d %d", &M, &V1, &V2, &T1, &T2);
    int slow_time = M / V1;
    int run_time = M / V2; 
    int rest_count = (run_time - 1) / T1;
    int fast_time = run_time + rest_count * T2;
    if (slow_time < fast_time)
        printf("1\n");
    else if (slow_time > fast_time)
        printf("2\n");
    else
        printf("0\n");
    return 0;
}
