#define _CRT_SECURE_NO_WARNINGS

//�ļ�����
//   c����Ĭ�ϵ���������� �� stdin��׼�����������̣�  stdout��׼���������Ļ��stderr��׼����������Ļ�� 
//   ע: 1.����pf �ɻ����������������
//       2.put����---���ļ����� "w"ģʽƥ��
//         get����---���ļ����� "r"ģʽƥ��
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

void text_fputc(FILE* pf)    //fputc(����1��int , ����2��FILE* stream);  ����1���ַ���Ӧ��ascII��ֵ .
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
						  //       (1)�� n <= pf ��һ���ַ����� ��FILE* stream �� n-1���ַ����� arr ��,���һ���ַ����'\0'
						  //       (2)�� n > pf ��һ���ַ��ĳ��ȣ������з���
						  //       (3)��ȡ�ַ�ʱ�����¼��ȡ����λ��
                          //���޷��ڶ�ȡ��ʱ�򷵻ؿ�ָ��(NULL)  n ==0 �� EOF
{
	char arr[100] = {0};

	printf("%s",fgets(arr,2,pf));
	printf("%s", fgets(arr, 2, pf));
	/*while (fgets(arr, 2, pf) != NULL)   
	{
		printf("%s",arr);
	}*/
}

void text_fprintf(FILE* pf)  //fprintf��printf����һ�� pf����ɴ��������������
{
	typedef struct S
	{
		char NAME[20];
		int age;
	}S;
	S s = { "����", 18 };
	fprintf(pf,"%s\n%d \n",s.NAME,s.age);
}

void text_fscanf(FILE* pf)           //fscanf��scanf ���˲��� FILE* stream ��ɴ�������������
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

void text_sprintf_sscanf()   //sprintf:�ǽ��ṹ�����ַ�������ʽ��ӡ
							 //sscanf: �ǽ��ַ��������ݴ���ṹ��
							 //������������Խṹ����ַ���
{
	typedef struct S
	{
		char NAME[20];
		int age;
	}S;
	S s = { "����", 18 };
	char arr[1024];
	sprintf(arr,"%s%d\n",s.NAME,s.age);
	printf("%s",arr);
	S s2 = { 0 };
	sscanf(arr, "%s%d", s.NAME, &s.age);
	printf( "s.NAME:%s\ns.age:%d\n", s.NAME, s.age);
}

void text_fwrite(FILE* pf)  // fwrite(const char* str , size_t , size_t num ,FILE* stream)
							// 1.str:     ָ��д��Ԫ�ص�ָ��
							// 2.size_t:  ��д��Ԫ�صĴ�С
							// 3.num:     Ԫ�ظ���
							// 4.stream:  ��д�����       -------�Զ�������ʽд��
{
	typedef struct S
	{
		char NAME[20];
		int age;
	}S;
	S s = { "����", 18 };
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
	//(1)���ļ�
	FILE* pf = fopen("data.txt", "rb");  //pf ָ������ά�����ļ������� 
	                                    //"r"���ļ���ʽ ��ȡ�ļ� --- �����ļ����ؿ�ָ��
										//"wb"�Զ����Ƶ���ʽ��������������
	if (pf == NULL)
	{
		printf("%s\n",strerror(errno)); //���ļ�ʧ�����ӡ������Ϣ
		return 1;
	}
	//(2)�����ļ�

	////////////////1.����fputc����
	//text_fputc(pf);


	
	///////////////2.����fgetc����
	/*int x = 12;
	while (x--)
	{
		int ch = text_fgetc(pf);
		printf("%c", ch);
	}*/


	//////////////3.����fputs����
	//text_fputs(pf);


	/////////////4.����fgets����
	//text_fgets(pf);


	/////////////5.����fprintf����
	//text_fprintf(pf);


	/////////////6.����fscanf����
	//text_fscanf(pf);


	/////////////7.����sprintf
	//text_sprintf_sscanf();

	/////////////8.����fwrite����
	//text_fwrite(pf);


	/////////////9.����fread����
	text_fread(pf);

	//(3)�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}