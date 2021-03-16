#define _CRT_SECURE_NO_WARNINGS

//文件操作
//   c语言默认的三个输出流 ： stdin标准输入流（键盘）  stdout标准输出流（屏幕）stderr标准错误流（屏幕） 
//   注: 1.以下pf 可换成任意输入输出流
//       2.put函数---与文件操作 "w"模式匹配
//         get函数---与文件操作 "r"模式匹配
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

void text_fputc(FILE* pf)    //fputc(参数1：int , 参数2：FILE* stream);  参数1是字符对应的ascII码值 .
{
	int i = 0;
	for (i = 'a'; i <= 'z'; i++)
	{
		fputc(i, pf);          
		fputc(' ', pf);
		fputc('\n', pf);
	}
}

int text_fgetc(FILE* pf)   //int fputc(FILE* stream)
{
	int ch = fgetc(pf);       
	return ch;
}

void text_fputs(FILE* pf)
{
	char arr[100] = "zwjzzzzzzz\naw\nfewf";
	fputs(arr, pf);
}

void text_fgets(FILE* pf) //fgets:
						  //       (1)若 n <= pf 中一行字符长度 则将FILE* stream 内 n-1个字符读入 arr 中,最后一个字符替成'\0'
						  //       (2)若 n > pf 中一行字符的长度，则将整行放入
						  //       (3)读取字符时，会记录读取到的位置
                          //当无法在读取的时候返回空指针(NULL)  n ==0 或 EOF
{
	char arr[100] = {0};

	printf("%s",fgets(arr,2,pf));
	printf("%s", fgets(arr, 2, pf));
	/*while (fgets(arr, 2, pf) != NULL)   
	{
		printf("%s",arr);
	}*/
}

void text_fprintf(FILE* pf)  //fprintf比printf多了一个 pf（其可代表任意输出流）
{
	typedef struct S
	{
		char NAME[20];
		int age;
	}S;
	S s = { "张三", 18 };
	fprintf(pf,"%s\n%d \n",s.NAME,s.age);
}

void text_fscanf(FILE* pf)           //fscanf比scanf 多了参数 FILE* stream 其可代表任意输入流
{
	typedef struct S
	{
		char NAME[20];
		int age;
	}S;
	S s = { 0 };
	fscanf(pf,"%s%d",&s.NAME,&s.age);
	printf("%s%d",s.NAME,s.age);
}

void text_sprintf_sscanf()   //sprintf:是将结构体以字符串的形式打印
							 //sscanf: 是将字符串的数据传入结构体
							 //这两个函数针对结构体和字符串
{
	typedef struct S
	{
		char NAME[20];
		int age;
	}S;
	S s = { "张三", 18 };
	char arr[1024];
	sprintf(arr,"%s%d\n",s.NAME,s.age);
	printf("%s",arr);
	S s2 = { 0 };
	sscanf(arr, "%s%d", s.NAME, &s.age);
	printf( "s.NAME:%s\ns.age:%d\n", s.NAME, s.age);
}

void text_fwrite(FILE* pf)  // fwrite(const char* str , size_t , size_t num ,FILE* stream)
							// 1.str:     指向被写入元素的指针
							// 2.size_t:  被写入元素的大小
							// 3.num:     元素个数
							// 4.stream:  被写入的流       -------以二进制形式写入
{
	typedef struct S
	{
		char NAME[20];
		int age;
	}S;
	S s = { "张三", 18 };
	fwrite(&s, sizeof(S), 1, pf); 
}

void text_fread(FILE* pf)
{
	typedef struct S
	{
		char NAME[20];
		int age;
	}S;
	S s = { 0 };
	fread(&s, sizeof(S), 1, pf);
	printf("%s %d",s.NAME,s.age);
}

int main()
{
	//(1)打开文件
	FILE* pf = fopen("data.txt", "rb");  //pf 指针用于维护打开文件的内容 
	                                    //"r"打开文件方式 读取文件 --- 若无文件返回空指针
										//"wb"以二进制的形式往流中输入数据
	if (pf == NULL)
	{
		printf("%s\n",strerror(errno)); //打开文件失败则打印错误信息
		return 1;
	}
	//(2)操作文件

	////////////////1.测试fputc函数
	//text_fputc(pf);


	
	///////////////2.测试fgetc函数
	/*int x = 12;
	while (x--)
	{
		int ch = text_fgetc(pf);
		printf("%c", ch);
	}*/


	//////////////3.测试fputs函数
	//text_fputs(pf);


	/////////////4.测试fgets函数
	//text_fgets(pf);


	/////////////5.测试fprintf函数
	//text_fprintf(pf);


	/////////////6.测试fscanf函数
	//text_fscanf(pf);


	/////////////7.测试sprintf
	//text_sprintf_sscanf();

	/////////////8.测试fwrite函数
	//text_fwrite(pf);


	/////////////9.测试fread函数
	text_fread(pf);

	//(3)关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}