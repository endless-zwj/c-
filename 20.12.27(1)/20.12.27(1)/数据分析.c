#define _CRT_SECURE_NO_WARNINGS
//��������һ��ѧ����ѧ�ţ��Լ�3�ƣ�C���ԣ���ѧ��Ӣ��ɼ�������Ļ�������ѧ����ѧ�ţ�3�Ƴɼ���
//�������� :
//ѧ���Լ�3�Ƴɼ���ѧ�źͳɼ�֮����Ӣ�ķֺŸ������ɼ�֮����Ӣ�Ķ��Ÿ�����
//������� :
//ѧ�ţ�3�Ƴɼ��������ʽ������������

//ʾ��1
//����

//17140216; 80.845, 90.55, 100.00
//���

//The each subject score of  No. 17140216 is 80.85, 90.55, 100.00.


#include <stdio.h>

struct student
{
	long ID;
	float C;
	float Math;
	float English;
};

int main()
{
	struct student s;
	scanf("%ld;%f,%f,%f", &(s.ID), &(s.C), &(s.Math), &(s.English));
	printf("The each subject score of No. %ld is %0.2f, %0.2f, %0.2f.", s.ID, s.C, s.Math, s.English);

	return 0;
}


