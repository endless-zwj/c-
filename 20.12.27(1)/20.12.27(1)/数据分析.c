#define _CRT_SECURE_NO_WARNINGS
//依次输入一个学生的学号，以及3科（C语言，数学，英语）成绩，在屏幕上输出该学生的学号，3科成绩。
//输入描述 :
//学号以及3科成绩，学号和成绩之间用英文分号隔开，成绩之间用英文逗号隔开。
//输出描述 :
//学号，3科成绩，输出格式详见输出样例。

//示例1
//输入

//17140216; 80.845, 90.55, 100.00
//输出

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


