#include <stdio.h>

struct time
{
    int hour;
    int minute;
};

int main()
{
    int n,i;
    scanf("%d", &n);
    struct time caughtTime[n], pastTime[n], currentTime[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d:%d", &caughtTime[i].hour, &caughtTime[i].minute);
        scanf("%d:%d", &pastTime[i].hour, &pastTime[i].minute);
    }
    for (int i = 0; i < n; i++)
    {
        int minute, hour;
        minute = caughtTime[i].minute + pastTime[i].minute;
        hour = caughtTime[i].hour + pastTime[i].hour;
        if (minute >= 60)
        {
            minute -= 60;
            hour += 1;
        }
        if (hour >= 24)
        {
            hour -= 24;
        }
        currentTime[i].hour = hour;
        currentTime[i].minute = minute;
    }
    for (int i = 0; i < n; i++)
        printf("%02d:%02d\n", currentTime[i].hour, currentTime[i].minute);
    return 0;
}
