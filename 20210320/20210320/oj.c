#define _CRT_SECURE_NO_WARNINGS

//#define ʵ�ֺ���offsetof

//ע��offsetof�������ã�����ṹ���Ա��ַ��ƫ����(�����Ԫ�ص�ַ)
//#include<stdio.h>

//#define OFFSETOF(StructType,Mem_name) ((int)&(((StructType*)0)->Mem_name))
//1.�Ȱ�0ת���ɽṹ�����͵�ָ�룬����0��������Ԫ�صĵ�ַ
//2.�ø�ָ����ʽṹ���Ա����Ա���׵�ַ�����ƫ����
//3.��ȡ����Ա�����ĵ�ַ������ֵǿתΪint�ͱ��
//struct S
//{
//	char a;
//	int b;
//	float c;
//};
//
//int main()
//{
//	printf("%d\n", OFFSETOF(struct S,a));
//	printf("%d\n", OFFSETOF(struct S,b));
//	printf("%d\n", OFFSETOF(struct S,c));
//	return 0;
//}

//�ú�ʵ�ֽ���һ���������Ƶ���żλ
#include<stdio.h>

#define SWAP(x)   ( ( (x)& 0xaaaaaaaa ) >>1  |   (((x)& 0x55555555)  <<1) )   
//(x)& 0xaaaaaaaa : 0xaaaaaaaa��ʾ�Ķ�����λΪ��101010.....101010(����ʮ��λ) 
//����x��&������λ�������䣬ż��λ��Ϊ0, ������Ϊ����λ������Ϊż��λ

//0x55555555: �����ƣ�010101.....0101 ����ͬ��

//�ٽ�������� | ���൱�ӷ������� ��õ���������żλ��������

int main()
{
	int a = 1;
	
	printf("%0x\n",a);
	printf("%0x\n",SWAP(a));
	return 0;
}
