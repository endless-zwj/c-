#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
		            <<< 1 >>>
		������  --->  �жϼ�����Ĵ�С�˴洢ģʽ

		        �������С����
		1.�������С����������Ա������
		2.������Ա��С������������������������Ҫ���롣
*/

int check_sys1()
{
	int a = 1 ;
	char* p = (char*)&a ;
	return *p ;  // С�˷��� 1 �� ��˷��� 0 ��
}

int check_sys2()
{
	union
	{
		char c;
		int i ;
	}u;
	u.i = 1;
	return u.c ;  // С�˷��� 1 ����˷��� 0 ��

}

int main()
{
	int ret1 = check_sys1();
	int ret2 = check_sys2();
	if (ret1 == 1)
		printf("sys1 :С�˴洢\n");
	else
		printf("sys1 :��˴洢\n") ;
	if (ret2 == 1)
		printf("sys2 :С�˴洢\n");
	else
		printf("sys2 :��˴洢\n");
	return 0 ;
}
