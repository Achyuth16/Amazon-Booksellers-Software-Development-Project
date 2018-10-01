#include <cctype>
void strupper(char* str)
{
	while (*str != 0) 
	{
		*str = toupper(*str);
		str++;
	}
}

