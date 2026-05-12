#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    int offset;
} TZ;

TZ tz_list[] = {
    {"HST", -600}, {"AKST", -540}, {"AKDT", -480},
    {"PST", -480}, {"PDT", -420}, {"MST", -420},
    {"CST", -360}, {"MDT", -360}, {"CDT", -300},
    {"EST", -300}, {"AST", -240}, {"EDT", -240},
    {"NST", -210}, {"ADT", -180}, {"NDT", -150},
    {"UTC", 0}, {"GMT", 0}, {"WET", 0},
    {"BST", 60}, {"IST", 60}, {"WEST", 60},
    {"CET", 60}, {"CEST", 120}, {"EET", 120},
    {"EEST", 180}, {"MSK", 180}, {"MSD", 240},
    {"AWST", 480}, {"ACST", 570}, {"AEST", 600},
    {"ACDT", 630}, {"AEDT", 660},
    {"", 0}
};


int get_offset(const char* tz)
{
    for (int i = 0; tz_list[i].name[0] != '\0'; i++)
    {
        if (strcmp(tz, tz_list[i].name) == 0)
            return tz_list[i].offset;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        char line[100];
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';
        char word1[20], word2[20], word3[20], word4[20];
        int cnt = sscanf(line, "%s %s %s %s", word1, word2, word3, word4);
        int total_minutes;
        if (cnt == 3)
        {
            char* origin = word2, * target = word3;
            if (strcmp(word1, "noon") == 0)
                total_minutes = 720;
            else
                total_minutes = 0;
            total_minutes = (total_minutes + get_offset(target) - get_offset(origin) + 1440) % 1440;
        }
        else
        {
            char* time_str = word1;
            char* ampm = word2;
            char* origin = word3, * target = word4;
            int h, m;
            sscanf(time_str, "%d:%d", &h, &m);
            if (strcmp(ampm, "a.m.") == 0)
            {
                if (h == 12)
                    h = 0;
            }
            else
            {
                if (h != 12)
                    h += 12;
            }
            total_minutes = h * 60 + m;
            total_minutes = (total_minutes + get_offset(target) - get_offset(origin) + 1440) % 1440;
        }
        if (total_minutes == 720)
            printf("noon\n");
        else if (total_minutes == 0)
            printf("midnight\n");
        else
        {
            int hour12 = total_minutes / 60;
            int minute = total_minutes % 60;
            const char* ampm_out;
            if (total_minutes < 720)
            {
                if (hour12 == 0)
                    hour12 = 12;
                ampm_out = "a.m.";
            }
            else
            {
                if (hour12 > 12)
                    hour12 -= 12;
                ampm_out = "p.m.";
            }
            printf("%d:%d %s\n", hour12, minute, ampm_out);
        }
    }
    return 0;
}
