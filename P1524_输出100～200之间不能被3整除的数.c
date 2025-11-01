#include <stdio.h>

int main()
{
	int count = 0;
	for (int num = 100; num <= 200; num++)//漏200WA
	{
		if (num % 3 != 0)
		{
			printf("%6d", num);
			count++;
			if (count % 6 == 0)
			{
				printf("\n");
			}
		}
	}
	if (count % 6 != 0)
	{
		printf("\n");
	}
	return 0;
}
