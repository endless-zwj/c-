#define _CRT_SECURE_NO_WARNINGS

//����������������������ʱ������
//����������ʱ������������������������

//#include <stdio.h>
//
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("����ǰ��a=%d,b=%d\n", a, b);
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("������a=%d,b=%d\n", a, b);
//	return 0;
//}



//Text 2 
//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������

//#include <stdio.h>
//int main()
//{
//	int a ;
//	scanf("%d", &a);
//	printf("������ż��λ: ");
//	for (int i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", a >> i);
//	}
//	printf("\n");
//	printf("������ż��λ: ");
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", a >> i);
//	}
//	printf("\n");
//	return 0;
//}


//Text 3
//����һ���������������32λ�����Ʊ�ʾ��1�ĸ��������и����ò����ʾ��

#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((a >> i) & 1) == 1)
			count++;
	}
	printf("%d\n", count);
	return 0;
}