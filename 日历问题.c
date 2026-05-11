#include <stdio.h>

int leap(int year)
{
	return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

const int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const char* weekdays[] = {"Sunday", "Monday", "Tuesday",
"Wednesday", "Thursday", "Friday", "Saturday"};

int main()
{
	int n;
	scanf("%d",&n);
	int week = (6 + n) % 7;
	int YYYY = 2000;
	while (1)
	{
		int yearlydays = leap(YYYY) ? 366 : 365;
		if (n >= yearlydays)
		{
			n -= yearlydays;
			YYYY++;
		}
		else
			break;
	}
	int MM = 1;
	while (1)
	{
		int monthlydays = month[MM - 1];
		if (MM == 2 && leap(YYYY))
			monthlydays++;
		if(n >= monthlydays)
		{
			n -= monthlydays;
			MM++;
		}
		else
			break;
	}
	int DD = n + 1;
	printf("%04d-%02d-%02d %s",YYYY,MM,DD,weekdays[week]);
}
