#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
�������飺
(1)���壺�ڽṹ���У������һ��Ԫ���ǲ��涨��С�����飨�ýṹ��Ԫ�ش���1���������鳤���ǵ��Կɱ��
*/

//example ---��������
typedef struct S1
{
	int n;
	int arr[];
}S1; // sizeof(S)����Ľṹ���Сδ������������Ĵ�С

//example ---����������
typedef struct S2
{
	int n;
	int* arr;
}S2;

int main1()
{
	// �ö�̬�ڴ�������һ������������Ľṹ�壺
	S1* ps = (S1*)malloc(sizeof(S1)+sizeof(int)* 10);//Ϊ�������鿪��40���ֽڵĿռ�
	
	return 0;
}

int main2()
{
	//����һ������������
	S2*ps = (S2*)malloc(sizeof(S2));
	int*a = (int*)malloc(sizeof(int)* 10);
}

//����������������
//(1)ֻҪmallocһ���ڴ棬���ڴ������������ٶȿ졣
//   ��������������malloc�����Ŀռ���Ƭ�࣬�ռ������ʵ�
//(2)������������Ҫ�ͷ������ڴ棬�����鷳

