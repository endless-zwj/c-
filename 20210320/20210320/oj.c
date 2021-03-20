#define _CRT_SECURE_NO_WARNINGS

//#define 实现函数offsetof

//注：offsetof函数作用：计算结构体成员地址的偏移量(相对首元素地址)
//#include<stdio.h>

//#define OFFSETOF(StructType,Mem_name) ((int)&(((StructType*)0)->Mem_name))
//1.先把0转换成结构体类型的指针，即用0来代表首元素的地址
//2.用该指针访问结构体成员，成员的首地址便成了偏移量
//3.再取出成员变量的地址，将该值强转为int型便可
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

//用宏实现交换一个数二进制的奇偶位
#include<stdio.h>

#define SWAP(x)   ( ( (x)& 0xaaaaaaaa ) >>1  |   (((x)& 0x55555555)  <<1) )   
//(x)& 0xaaaaaaaa : 0xaaaaaaaa表示的二进制位为：101010.....101010(共三十二位) 
//其与x相&，奇数位的数不变，偶数位变为0, 右移以为奇数位的数变为偶数位

//0x55555555: 二进制：010101.....0101 操作同上

//再将两结果相 | （相当加法操作） 便得到二进制奇偶位交换的数

int main()
{
	int a = 1;
	
	printf("%0x\n",a);
	printf("%0x\n",SWAP(a));
	return 0;
}
