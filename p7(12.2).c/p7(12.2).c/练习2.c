#define _CRT_SECURE_NO_WARNINGS
//��д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼���Ρ�
//ֻ�����������룬���������˳�����

#include<stdio.h>
#include<string.h>
int main()
{
	char password[] = "12345";    //�������Ϊ 12345 abcd Ҫ��ô��Ƴ���

	int i = 0;
	char arr[20];

	for (i = 0; i < 3; i++)
	{
		
		scanf("%s", arr);

		if (strcmp(arr, password) == 0)
		{
			printf("��¼�ɹ�\n");
		    break;
		}
	}

	if (strcmp(arr, password) != 0)
		printf("���ź���ϵͳ�����˳�\n");

	return 0;
}
