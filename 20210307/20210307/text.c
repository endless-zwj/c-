#define _CRT_SECURE_NO_WARNINGS
/*
		      <<<< 1 >>>>
		         λ��
1.λ�γ�Ա������ int unsigned int  signed int char 
2.λ�εĿռ䰴�� 4�ֽڣ�int�� /  1�ֽ� ��char�� ����
3.λ���漰�ܶ಻ȷ�����أ�λ�β���ƽ̨��
*/

//example 1
#include <stdio.h>

struct S
{
	char a : 3 ; // a ���� 3  �� bit λ��
	char b : 4 ; // b ���� 4  �� bit λ�� 
	char c : 5 ;
	char d : 4 ; 
};

int main()
{
	struct S s = { 0 };
	s.a = 10;
	s.b = 20;
	s.c = 3;
	s.d = 4;

	/*
	   vs �� һ���ֽ� 0 0 0 0 0 0 0 0
						[   b ][  a ]
	   �������󿪱ٿռ�
	   ���޷����õĿռ����
	*/

	printf("%d\n", s.a); // 2  (ֻȡ3λbitλ�ڵ���)
	printf("%d\n", s.b); // 4  (ֻȡ4λbitλ�ڵ���)
	printf("%d\n", s.c); // 3
	printf("%d\n", s.d); // 4
	return 0 ;

}
