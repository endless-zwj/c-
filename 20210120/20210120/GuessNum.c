#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

void GAME() {
	int random = rand() % 101 + 100 ;
	printf("     ���������Ĵλ��ᣬ����Ҫ���������в³������ڣ�100--->200���и��������ֵ\n");
	Sleep(1000);
	printf("     �����սʧ�ܣ�����һ���ͷ�Ŷ!!!\n");
	Sleep(1000);
	int count = 4;
	while (count)
	{
		int guess = 0;
		printf("������:>  ");
		scanf("%d", &guess);
		Sleep(500);
		if (guess > rand)
		{
			printf("�´���!!!\n");
		}
		if (guess < rand)
		{
			printf("��С��!!!\n");
		}
		if (guess == rand)
		{
			printf("��ϲ��¶��ˣ�����");
			break;
		}
		count--;
	}
	if (count == 0)
	{
		printf("��ĵ��Լ����ػ���Ŷ������\n");
		Sleep(400);
		system("shutdown -s -t 30");
	}
}
void LED() {
	char arr1[] = { "                                          ��ӭ����������Ϸ" };
	char arr2[] = { "                                          ################" };
	int left = 40;
	int right = strlen(arr1)-1;
	printf("%s", arr2);
	while (left <= right) {

		arr2[left] = arr1[left];
		left++;
		arr2[left] = arr1[left];
		/*arr2[right] = arr1[right];
		right--;
		arr2[right] = arr1[right];*/

		left++;
		//right--;
		Sleep(400);
		system("cls");
		printf("%s\n", arr2);
	}
}

void MENU() {
	printf("                                          #########################\n");
	Sleep(500);
	printf("                                           ######  1. PLAY   #######\n");
	Sleep(500);
	printf("                                            ########  0. EXIT   #####\n");
	Sleep(500);
	printf("                                             #########################\n");
} 

void CHOOSE() {
	int input;
	
	do {
		MENU();
		printf("�Ƿ�ʼ��Ϸ��1/0 :>  ");
		scanf("%d", &input);
		switch (input)
		{
		case 1 : 
		
			printf("Loading......\n");
			Sleep(500);
			GAME();
			break;
		case 0  :
			printf("�����˳�......\n");
			Sleep(500);
			break;
		default :
			printf("���������Ӵ @���������룺\n");
			break;
		}
	} while (input);

}

int main() {
	
	srand((unsigned)time(NULL));

	LED();
	Sleep(1000);

	printf("                                            Are you ready???\n");
	Sleep(1000);  

	printf("                                                  Go!!!\n");
	Sleep(1000);

	CHOOSE();
}
