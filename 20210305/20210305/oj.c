#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//ʵ�� ʹ i like beijing. --> beijing. like i ���


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
			count--; //����һ���ַ�  ���� �ַ���һ
			Index--; //�±�ָ����ַ�ǰһ���ַ�
			num++;   //��¼һ�����ʵĳ��ȣ���Ϊ һ�� �ַ�ת�� ��ѭ���Ĵ���
		}
		if (count > 0)//��Ϊ�����������ַ����������м�ո� ��count--��
		{
			count--;
		}
		Index += 1;  // Str[Index] ָ����ǵ���ǰ�Ŀո�

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