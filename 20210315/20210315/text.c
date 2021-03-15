#define _CRT_SECURE_NO_WARNINGS

// 动态内存管理出现的几道  错误事例
//     <<1>>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void* GetMemory(char** p)
//{
//	*p = (char*)malloc(20);
//}
//
//int main()
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	//没有释放内存，会造成内存泄漏
//	return 0;
//}

//     <<2>> 
//#include<stdio.h>
//char* GetMemory()
//{
//	char p[] = "hello world!";
//	return p;  //p为局部变量，出函数内存销毁,但p存的地址不变
//}
//
//int main()
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);//非法访问内存
//	return 0; 
//}


