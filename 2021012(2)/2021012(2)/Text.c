#define _CRT_SECURE_NO_WARNINGS

Text1  �ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
#include <stdio.h>

void  func(int n)
{
	if (n / 10 == 0)
		printf("%d ", n);
	else
	{
		func(n / 10);
		printf("%d ", n % 10);
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	func(n);
	return 0;
}




