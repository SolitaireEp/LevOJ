#include <stdio.h>

int main() 
{
    char s;
    for (; (s = getchar()) != '\n'; ) 
    {
        if (s == '*') 
            putchar(s);
        else
        {
			putchar(s);
			break;
        }
	}
    for(; (s = getchar()) != '\n'; ) 
    {
        if (s != '*') 
            putchar(s);
	}
    return 0;
}
