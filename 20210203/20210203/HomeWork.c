#define _CRT_SECURE_NO_WARNINGS
//  Text 1 在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//……
//#include <stdio.h>
//int main()
//{
//	int n ;
//	int arr[100][100];
//	scanf("%d", &n) ;// n 代表行
//
//	int i, j ;
//	for (i = 0 ; i <  n  ; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (i == j)
//			{
//				arr[i][j] = 1;
//				printf("%d ", arr[i][j]);
//			}
//			else if (j != 0 )
//			{
//				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//				printf("%d ", arr[i][j]);
//			}
//			else
//			{
//				arr[i][j] = 1 ;
//				printf("%d ",arr[i][j]);
//			}
//		}
//		printf("\n") ;
//	}
//	return 0 ;
//}


// Text 2 日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

//#include <stdio.h>
//int main()
//{
//	int Killer[4] = { 0 };
//	int i = 0;
//	for (i=0 ; i < 4; i++)
//	{
//		Killer[i] = 1 ; //假定凶手
//		if ((Killer[0] != 1) + (Killer[2] == 1) + (Killer[3] == 1) + (Killer[3] != 1)== 3)
//			break;
//		Killer[i] = 0 ; //排除嫌疑
//	}
//	printf("凶手是%c\n ", 'A' + i);
//	return 0 ;
//}


//Text 3 5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
#include <stdio.h>
int checkdata( int * p)
{
	int tmp[7] = { 0 }; //标记表，实际是哈希表的思路。一开始每个元素都是0。

	int i;
	for (i = 1; i <= 5; i++)
	{
		if (tmp[p[i]]) //如果这个位置的标记已经是1，则代表重复，直接返回0。
		{
			return 0;
		}
		tmp[p[i]] = 1; //如果不是，则给这个位置标记为1。
	}
	return 1; //全部标记完毕也没有出现重复的情况，代表OK。
}

int main()
{
	int p[6] = { 0 };
	int i ;
	
	for (p[1] = 1; p[1] <= 5; p[1]++)
	{
		for (p[2] = 1; p[2] <= 5; p[2]++)
		{
			for (p[3] = 1; p[3] <= 5; p[3]++)
			{
				for (p[4] = 1; p[4] <= 5; p[4]++)
				{
					for (p[5] = 1; p[5] <= 5; p[5]++)
					{
						if (((p[2] == 2) + (p[1] == 3) == 1) &&
							((p[2] == 2) + (p[5] == 4) == 1) &&
							((p[3] == 1) + (p[4] == 2) == 1) &&
							((p[3] == 5) + (p[4] == 3) == 1) &&
							((p[5] == 4) + (p[1] == 1) == 1) &&
							checkdata(p)
							)
								for (i = 1; i <= 5; i++)
								{
									printf("%d ", p[i]);
								}
					}
				}
			}
		}
	}
	return 0 ;
}