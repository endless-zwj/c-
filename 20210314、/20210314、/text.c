#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//  ��̬�ڴ���� -- malloc/free ����
//int main()
//{
//	int* p = (int*)malloc(sizeof(int)* 10);
//	//�����ڴ�ʧ��
//	if (p == NULL)
//	{
//		//��ӡ������Ϣ
//		printf("%s\n",strerror(errno));
//	}
//	else
//	{
//		//����ʹ�ÿռ�
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ",*(p+i));
//		}
//		free(p);//ָ�������ͷ�Ϊ�գ�����ָ��û�����ı䣨�������ڶ�����ʣ�����ɷǷ������ڴ棩
        //            <freeע������>
        // free����ֻ�ܶԶ�̬�ڴ�����ݽ����ͷţ�������
		// free�����ͷ�һ�ζ�̬�ڴ�ռ䣬Ҫ��һ�������Ŀռ�ȫ���ͷ�
		//���ܶ�ͬһ��ռ����ͷ� ����������ͷ����ԭָ����Ϊ��

//		printf("%d\n", *p); //��ʱ���������Ϊ���ֵ
//		p = NULL;
//	}
//
//	return 0;
//}

//  ��̬���ڴ����------calloc����
//int main()
//{
//	int* arr = (int*)calloc(10,sizeof(int));//��һ������Ԫ�ظ��� ���ڶ�������ÿ��Ԫ�صĴ�С
//	//calloc��ʼ���ռ�ȫΪ��
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ",*(arr+i));
//	}
//	printf("\n");
//	printf("1234");
//	free(arr);
//	return 0;
//}

// ��̬�ڴ���� --- realloc����  ���ݺ���

/*
	realloc����ԭ��:
	1.���p����Ŀռ��㹻����reallocֱ����p����ƴ��һ�οռ䣬������ԭֵp
	2.���p����Ŀռ䲻������realloc�����ڶ������¿���һ��ռ䣬�������µ�ַ(ԭ���ݲ��ı䣬�������ݲ���ʼ��)
	3.���realloc���ٿռ�ʧ�ܣ��򷵻�NULL����˲���ֱ����ԭָ�����realloc�ķ���ֵ
	4.realloc������һ���������ΪNULL��������Ч�� = malloc
*/
int main()
{
	int* p = calloc(10, 4);
	int* ptr = realloc(p, 20 * 4);
	if (ptr != NULL)
	{
		p = ptr;
		for (int i = 0; i < 20; i++)
		{
			printf("%d ", *(p + i));
		}
		free(p);
	}
	
	return 0;

}
