#define _CRT_SECURE_NO_WARNINGS
//// Text 1 : ʵ��My_strlen����
////��1 ����ָ�� - ָ�롱ʵ�� 
//#include <stdio.h>
//int My_strlen1(char* ps ) 
//{
//	char* pe = ps ;
//	while ( *pe++ )
//	{
//		;
//	}
//	pe--;//ʹβָ��ָ��\0ǰһ���ַ�
//	return pe - ps ;
//}
//
//// ��2 ���ݹ�ʵ��
//int My_strlen2(char* p)
//{
//	if (*++p == 0)
//	{
//		return 1;
//	}
//	else
//		return 1 + My_strlen2(p++);
//}
//
//int main()
//{
//	char* p = "asfgede";
//	int ret1 = My_strlen1(p);
//	int ret2 = My_strlen2(p);
//	printf("%d\n%d\n", ret1,ret2);
//	return 0;
//}

////Text 2: ʵ��My_strcpy����
//#include <stdio.h>
//char* My_strcpy(char* des, const char* src)
//{
//	char* p = des;
//	while (*p++ = *src++)
//	{
//		;
//	}
//	return  des;
//}
//
//int main()
//{
//	char arr1[100] = "hello world";
//	char arr2[100] = "hello bit";
//	printf("%s\n", My_strcpy(arr1, arr2));
//	return 0 ;
//}

//// Text 3 ʵ��My_strcmp
//#include <stdio.h>
//int My_strcmp1(char* p1, char* p2)
//{
//	while (*p1 && *p2)
//	{
//		if ((*p1++) != (*p2++))
//		{
//			return *p1 - *p2 ;
//		}
//	}
//	return *p1 - *p2;
//}
//
//int My_strcmp2(char* p1, char* p2)
//{
//	while (*p1 == *p2)
//	{
//		if (*p1 == 0)
//		{
//			return 0;
//		}
//		p1++;
//		p2++;
//	}
//	return *p1 - *p2;
//}
//
//int main()
//{
//	char arr1[100] = "hello world";
//	char arr2[100] = "hello bit";
//	int ret = My_strcmp2(arr1, arr2);
//	if (ret == 0)
//	{
//		printf("str1 = str2\n");
//	}
//	else if(ret > 0)
//	{
//		printf("str1 > str2\n");
//	}
//	else
//	{
//		printf("str1 < str2\n");
//	}
//	return 0;
//}


////Text 4 ʵ��My_strcat
//#include <stdio.h>
//char* My_strcat(char* des , const char* src)
//{
//	char* p = des;
//	while (*p)
//	{
//		p++;
//	}
//	while (*p++ = *src++)
//	{
//		;
//	}
//	return des;
//}
//
//int main()
//{
//	char arr1[100] = "hello world";
//	char arr2[100] = "hello bit";
//	printf("%s\n", My_strcat(arr1,arr2) ); 
//	return 0 ;
//}


//Text 5 ʵ��strstr����
//       Ҫ����ĸ�������Ӵ�
#include <stdio.h>
char* My_strstr(char* des, char* src)
{
	char* rev = src;
	char* ret = NULL;
	while (*des)
	{
		while (*des != *src  && *des != 0)
		{
			des++;
		}
		if (*des == *src)
		{
			ret = des;
			while (*des == *src)
			{
				if (*(++src) == '\0')
					return ret;
				des++;
			}
			src = rev;
			des = ++ret;
			ret = NULL;
		}
		
	}
	return ret;
}

int main()
{
	char arr1[100] = "zzxcfgh";
	char arr2[100] = "zx";
	char* ret = My_strstr(arr1, arr2);
	printf("%s\n", ret);
	return 0;
}
