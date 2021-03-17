#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

//文件操作
// fread.fseek.ftell.rewind

typedef struct S
{
	char name[20];
	int age ;
}S;

void text_fwrite_fread(FILE* pf)
{
	S s1 = { "张三", 18 };
	//fwrite(&s1, sizeof(S), 1, pf);

	S s2 = { 0 };
	while (fread(&s2, sizeof(S), 1, pf)) //fread函数第三个参数表示每次从pf中读取的最大num个数据
										 //若读出的个数小于num,则返回读取的个数
	{
		printf("%s\n",s2.name);
		printf("%d\n",s2.age);
	}
}


int main()
{
	//打开文件
	FILE* pf = fopen("text.dat", "rb");
	if (pf == NULL)
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	//操作文件

	/////////////////测试text_fwrite_fread
	text_fwrite_fread(pf);

	//关闭文件
	fclose(pf);
	return 0;
}
