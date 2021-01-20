#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

void GAME() {
	int random = rand() % 101 + 100 ;
	printf("     规则：你有四次机会，你需要在这三次中猜出电脑在（100--->200）中给出的随机值\n");
	Sleep(1000);
	printf("     如果挑战失败，会有一定惩罚哦!!!\n");
	Sleep(1000);
	int count = 4;
	while (count)
	{
		int guess = 0;
		printf("请输入:>  ");
		scanf("%d", &guess);
		Sleep(500);
		if (guess > rand)
		{
			printf("猜大了!!!\n");
		}
		if (guess < rand)
		{
			printf("猜小了!!!\n");
		}
		if (guess == rand)
		{
			printf("恭喜你猜对了！！！");
			break;
		}
		count--;
	}
	if (count == 0)
	{
		printf("你的电脑即将关机了哦！！！\n");
		Sleep(400);
		system("shutdown -s -t 30");
	}
}
void LED() {
	char arr1[] = { "                                          欢迎来到猜数游戏" };
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
		printf("是否开始游戏（1/0 :>  ");
		scanf("%d", &input);
		switch (input)
		{
		case 1 : 
		
			printf("Loading......\n");
			Sleep(500);
			GAME();
			break;
		case 0  :
			printf("正在退出......\n");
			Sleep(500);
			break;
		default :
			printf("输入错误了哟 @请重新输入：\n");
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
