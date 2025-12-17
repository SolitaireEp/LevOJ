#include <stdio.h>

int main()
{
	char str[100];
	int n;
	gets(str);
	scanf("%d", &n);
	for (int i = 0; i < 100; i++) {
		if (str[i] == '\0') {
			break;
		}
		if (i < n) {
			putchar(str[i]);
		}
		else {
			putchar(str[n - 1]);
		}
	}
	printf("\n");
	for (int i = 0; i < 100; i++) {
		if (str[i] == '\0') {
			break;
		}
		if (i < n) {
			putchar(str[n]);
		}
		else {
			putchar(str[i]);
		}
	}
}
/*我自己写的没找到错在哪...
#include <stdio.h>
int main()
{
	char str[100];
	int n,i;
	fgets(str, 100, stdin);
	scanf("%d", &n);
	for (i = 0; i < 100; i++) 
	{
		if (str[i] == '\0' || str[i] == '\n')
			break;
		if (i < n)
			putchar(str[i]);
		else
			putchar(str[n - 1]);
	}
	printf("\n");
	for (i = 0; i < 100; i++)
	{
		if (str[i] == '\0' || str[i] == '\n')
			break;
		if (i < n)
			putchar(str[n]);
		else
			putchar(str[i]);
	}
}*/
