#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

//�ļ�����
// fread.fseek.ftell.rewind

typedef struct S
{
	char name[20];
	int age ;
}S;

void text_fwrite_fread(FILE* pf)
{
	S s1 = { "����", 18 };
	//fwrite(&s1, sizeof(S), 1, pf);

	S s2 = { 0 };
	while (fread(&s2, sizeof(S), 1, pf)) //fread����������������ʾÿ�δ�pf�ж�ȡ�����num������
										 //�������ĸ���С��num,�򷵻ض�ȡ�ĸ���
	{
		printf("%s\n",s2.name);
		printf("%d\n",s2.age);
	}
}


int main()
{
	//���ļ�
	FILE* pf = fopen("text.dat", "rb");
	if (pf == NULL)
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	//�����ļ�

	/////////////////����text_fwrite_fread
	text_fwrite_fread(pf);

	//�ر��ļ�
	fclose(pf);
	return 0;
}
