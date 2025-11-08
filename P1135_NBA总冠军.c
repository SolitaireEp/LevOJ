#include <stdio.h>
#include <string.h>

struct Champion
{
    char city[81];
    int year;
};

int main() 
{
    int n,i,j;
    scanf("%d", &n);
    getchar();
    struct Champion champs[80] = {0};
   for(i=0;i<n;i++)
   {
        char input[200];
        fgets(input, sizeof(input), stdin);
        input[strlen(input)] ='\0';
        int len = strlen(input);
        int space_pos = -1;
        for (int j = len - 1; j >= 0; j--) 
        {
            if (input[j] == ' ') 
            {
                space_pos = j;
                break;
            }
        }
        strncpy(champs[i].city, input, space_pos);
        champs[i].city[space_pos] = '\0';
        char year_str[5];
        strncpy(year_str, input + space_pos + 1, 4);
        year_str[4] = '\0';
        champs[i].year =(year_str[0]-'0')*1000+ (year_str[1] - '0') * 100+(year_str[2] - '0') * 10+ (year_str[3] - '0');
   }
   for (i = 0; i < n - 1; i++)
   {
       for(j = 0; j < n - i - 1; j++)
       {
           if (champs[j].year > champs[j + 1].year)
           {
               struct Champion temp = champs[j];
               champs[j] = champs[j + 1];
               champs[j + 1] = temp;
           }
	   }
   }
    printf("%d %s\n", champs[0].year, champs[0].city);
    for (int i = 1; i < n; i++) 
    {
        if (champs[i].year != champs[i - 1].year) 
        {
            printf("%d %s\n", champs[i].year, champs[i].city);
        }
    }
    return 0;
}
