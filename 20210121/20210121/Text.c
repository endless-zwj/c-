#define _CRT_SECURE_NO_WARNINGS
// text 1 判断一个数是否为素数(100-->200)

#include <stdio.h>
int main() {
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++) {
		int j = 2;
		for (j = 2; j < i; j++) {
			if (i % j == 0) {
				break;
			}
		}
		if (i == j) {
			printf("%d ", i);
			count++;
			if (count % 5 == 0)
			{
				printf("\n");
			}
		
		}
		
	}
	return 0;
}

// Text 2
// 实现函数判断year是不是润年。

#include <stdio.h>

int IsLeapyear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int year;
	while (scanf("%d", &year) )
	{
		int ret = IsLeapyear(year);
		if (ret == 1)
		{
			printf("%d 是闰年\n",year);
		}
		else
		{
			printf("%d 不是闰年\n", year);
		}
	}
	return 0;
}


//Text 3
//写一个函数来交换两个整数

void Swap(int* x, int* y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	int a = 10;
	int b = 20;
	printf("%d %d\n", a, b);
	Swap(&a, &b);
	printf("%d %d", a, b);
}


//Text 4
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表

#include <stdio.h>
int main()
{
	int i;
	int n;
	while (scanf("%d", &n))
	{
		for (i = 1; i <= n; i++)
		{
			int j = 1;
			for (j = 1; j <= i; j++)
			{
				printf("%d*%d =%-3d", j, i, i*j);
			}
			printf("\n");
		}
	}
	
	return 0;
}



//Text 5 
//公务员面试现场打分。有7位考官，从键盘输入若干组成绩，每组7个分数（百分制）
//去掉一个最高分和一个最低分，输出每组的平均成绩。


#include <stdio.h>
void Swap(float* a, float* b)
{
	float tmp = *a;
	*a = *b;
	*b = tmp;
}

void Delete(float score[])
{

	for (int i = 0; i<7; i++)
	{
		if (score[i]>score[5])
		{
			Swap(&score[i], &score[5]);
		}
	}
	for (int i = 0; i<7; i++)
	{
		if (score[i]<score[6])
		{
			Swap(&score[i], &score[6]);
		}
	}
}

float AverSum(float score[])
{
	float sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += score[i];
	}
	return sum / 5;

}


int main()
{
	int i = 0;
	float score[7];
	for (i = 0; i < 7; i++)
	{
		scanf("%f", &score[i]);
	}
	float score2[5];
	Delete(score);
	float ret = AverSum(score);
	printf("%.2f", ret);
	return 0;
}

//text 输出每年月份天数
#include <stdio.h>
int main()
{
	int year, month;
	int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (scanf("%d%d", &year, &month) != EOF)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if (month == 2)
				printf("%d\n", day[month - 1] + 1);
			else
				printf("%d\n", day[month - 1]);
		}
		else
			printf("%d\n", day[month - 1]);
	}
	return 0;
}