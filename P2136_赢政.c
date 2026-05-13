#include <stdio.h>

int monthly(int year, int month)
{
    if (month == 2 && year == 2028)
        return 29;
    if (month == 2 && year != 2028)
        return 28;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    return 31;
}

int days(int y1, int m1, int d1, int y2, int m2, int d2)
{
    int total = 0;
    int y = y1, m = m1, d = d1;
    while (y < y2 || m < m2 || d < d2)
    {
        total++;
        d++;
        if (d > monthly(y, m))
        {
            d = 1;
            m++;
            if (m > 12)
            {
                m = 1;
                y++;
            }
        }
    }
    total++;
    return total;
}

int birthday(int y1, int m1, int d1, int y2, int m2, int d2)
{
    int cnt = 0;
    for (int y = y1; y <= y2; y++)
    {
        if (y == y1 && (m1 > 6 || (m1 == 6 && d1 > 14)))
            continue;
        if (y == y2 && (m2 < 6 || (m2 == 6 && d2 < 14)))
            continue;
        cnt++;
    }
    return cnt;
}

int main()
{
    int y, m, d, ds;
    scanf("%d %d %d", &y, &m, &d);
    ds = days(2025, 1, 20, y, m, d);
    int bdays = birthday(2025, 1, 20, y, m, d);
    printf("%d\n", ds + bdays);
    return 0;
}
