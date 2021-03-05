#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//实现 使 i like beijing. --> beijing. like i 输出


int My_strlen(char * p)
{
	int count = 0;
	while ((*p) != '\0')
	{
		count++;
		p++;
	}
	return count;
}

int main()
{
	int Index2 = 0;
	int Index = 0;
	char Str1[100];
	char Str2[100];
	
	gets(Str1);
	int count = My_strlen(Str1);

	while (count)
	{
		int num = 0;
		Index = count - 1;
		while ((Str1[Index] != ' ') && Index >= 0)
		{
			count--; //遍历一个字符  便让 字符减一
			Index--; //下标指向该字符前一个字符
			num++;   //记录一个单词的长度，即为 一次 字符转移 需循环的次数
		}
		if (count > 0)//若为遍历完所有字符，便跳过中间空格 即count--；
		{
			count--;
		}
		Index += 1;  // Str[Index] 指向的是单词前的空格

		while (num)
		{
			Str2[Index2] = Str1[Index];
			Index2++;
			Index++;
			num--;
		}
		if (count != 0)
		{
			Str2[Index2] = ' ';
			Index2++;
		}
	}
	Str2[Index2] = '\0';
	puts(Str2);

	return 0;
}