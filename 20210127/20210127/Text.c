#define _CRT_SECURE_NO_WARNINGS

// Text 1 
//дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
//arr��һ������һά���顣

//#include <stdio.h>
//
//void print(int* p, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//
//int main()
//{
//	int arr[5] = { 2, 4, 5, 6, 7 };
//	int sz = sizeof(arr) / sizeof (arr[0]);
//	print(arr, sz);
//	return 0;
//}


// Text 2 �ַ�������
//����
//I am a student
//���
//tneduts a ma I

//#include <stdio.h>
//#include <string.h>
//
//void reverse(char* p, int sz)
//{
//	for (int i = sz - 1; i >= 0; i--)
//	{
//		printf("%c", *(p + i));
//	}
//}
//
//int main()
//{
//	char arr[100];
//	while (gets(arr))
//	{
//		int sz = strlen( arr );
//		reverse(arr, sz);
//	}
//	return 0;
//}


//Text 3 
//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222

//#include <stdio.h>
//#include <math.h>
//
//int Sn(int a, int n)
//{
//	if (n == 1)
//		return a ;
//	else
//	{
//		int ret = 0 ;
//		for (int i = 0; i < n; i++)
//		{
//			ret += a * (int)pow( 10 , i);
//		}
//		return  ret + Sn( a , n - 1);
//	}
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int n = 5 ;
//	int sum = Sn( a , n);
//	printf("%d\n", sum);
//	return 0;
//}

//Text 4
//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ��������� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	for (int i = 0; i <= 100000; i++)
//	{
//		int sum = 0;
//		int j = i % 10;
//		int x = i ;
//		int count = 1;
//		while (x/10)
//		{
//			x /= 10 ;
//			count++;
//		}
//		x = i ;
//		while (x)
//		{
//			sum += (int)pow((x % 10) , count ) ;
//			x /= 10 ;
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0 ;
//}

// Text 5

//#include <stdio.h>
//int main()
//{
//	int i, j ,k;
//	for (i = 0; i < 13; i++)
//	{
//		if (i < 7)
//		{
//			for (j = 1; j <= 13; j++)
//			{
//				if (j>=7 - i && j <= 7 + i)
//					printf("*");
//				else
//					printf(" ");
//			}
//		}
//		else
//		{
//
//			for (j = 1; j <= 13; j++)
//			{
//				if (j>= i - 5  && j <= 13 - (i-6))
//					printf("*");
//				else
//					printf(" ");
//			}
//		}
//		printf("\n");
//	
//	}
//	return 0;
//}

//Text 6
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
#include <stdio.h>
int main()
{
	int count = 20 ; 
	int n = 20 ; 
	while (n >= 2)
	{
		if (n % 2 == 1)
		{
			count += (n - 1) / 2;
			n = (n - 1) / 2 + 1 ;
		}
		else
		{
			count += n / 2;
			n = n / 2 ;
		}
	}
	printf("%d\n",count);
	return 0;
}