#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
                  <<<<<< 1 >>>>>>
                  �ṹ���ڴ���룺
1.��һ����Ա�����ڽṹ�����ƫ����Ϊ0��ַ����
2.������Ա����Ҫ���뵽ĳ�����֣������������������ĵ�ַ��
     ������ = min��������Ĭ�϶��������ó�Ա��С��
     vs��Ĭ��Ϊ 8
3.�ṹ���ܴ�СΪ������������������
4.Ƕ�׽ṹ������£�Ƕ�׽ṹ���뵽�ýṹ��������������������
*/

struct S1
{
	char a;
	int  b;
	char c;
};//12

struct S2
{
	char a;
	char b; 
	int  c;
};//8

/*
			    <<<<< 2 >>>>>>
				�޸�Ĭ�϶�����
#pragma pack(�޸�ֵ) --->�޸�Ĭ�϶�����
 .....(�ṹ��)
#pragma pack()       --->ȡ��Ĭ�϶�����
*/

/*
               <<<<<< 3 >>>>>>>
			  ��ʵ��������ƫ����
offsetof(struct S1 ,����)
*/

int main()
{
	printf("%d,%d",sizeof(struct S1),sizeof(struct S2));
	printf("\n");
	return 0;
}
