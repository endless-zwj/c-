#define _CRT_SECURE_NO_WARNINGS

//Text 1
//��ŵ������

//#include <stdio.h>
//
//void move(char pos1, char pos2)
//{
//	printf("%c%s%c ", pos1, "-->", pos2);
//}
//
//// n : ���Ӹ���
//// pos1 :  ��ʼλ��
//// pos2 :  �м�λ��
//// pos3 :  Ŀ��λ��
//
//void Hanoi(int n , char pos1 , char pos2 , char pos3)
//{
//	if (n == 1)
//	{
//		move(pos1, pos3);
//	}
//	else
//	{
//		Hanoi(n - 1, pos1, pos3, pos2);
//		move(pos1, pos3);
//		Hanoi(n - 1, pos2 , pos1 , pos3 );
//	}
//}
//
//#include <stdio.h>
//int main()
//{
//	int n;
//	char pos1 = 'A';
//	char pos2 = 'B';
//	char pos3 = 'C';
//	while (scanf("%d", &n) != EOF)
//	{
//		Hanoi(n, pos1, pos2, pos3);
//	}
//	return 0;
//}



//Text 2
//������̨������ һ�ο���һ�׻�����

#include <stdio.h>

int Jump(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}else 
	{
		return Jump(n - 1) + Jump(n - 2);
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int ret = Jump(n);
		printf("��%d������\n", ret);
	}

	return 0;
}