#define _CRT_SECURE_NO_WARNINGS
//ÊµÀý ÊµÏÖ i like beijing. ---> beijing.like i

#include <stdio.h>
#include <string.h>
void reverse(char* left, char* right)
{
	char tmp;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	char Str[100];
	gets(Str);
	int len = strlen(Str);
	reverse(Str, Str + len - 1);
	char* start = Str;
	char* end = start;
	while ((*end) != '\0')
	{
		start = end;
		while (*(end + 1) != ' '&& *(end+1) != '\0')
		{
			end++;
		}
		reverse(start, end);
		if (*(end + 1) != '\0')
		{
			end += 2 ;
		}
		else
		{
			break;
		}
	
	}
	printf("%s\n", Str);
	return 0;
}
