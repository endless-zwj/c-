#define _CRT_SECURE_NO_WARNINGS
// text 1 �ж�һ�����Ƿ�Ϊ����(100-->200)

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
// ʵ�ֺ����ж�year�ǲ������ꡣ

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
			printf("%d ������\n",year);
		}
		else
		{
			printf("%d ��������\n", year);
		}
	}
	return 0;
}


//Text 3
//дһ��������������������

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
//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//�磺����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���

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
//����Ա�����ֳ���֡���7λ���٣��Ӽ�������������ɼ���ÿ��7���������ٷ��ƣ�
//ȥ��һ����߷ֺ�һ����ͷ֣����ÿ���ƽ���ɼ���


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

//text ���ÿ���·�����
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