#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main()
{

	char arr[20] = { "0" };
	system ("shutdown -s -t 60");
	printf("���Լ����ػ���������: ������ ֹͣ�ػ�\n");


	again:
		printf("�����룺");
		scanf("%s", arr);
		if (0 == strcmp("������", arr))
		{
			printf("��ֹͣ�ػ�\n");
			system("shoutdowm -a ");
		}
		else
		{
			printf("�������������\n");
			goto again;
		}


	return 0;
}