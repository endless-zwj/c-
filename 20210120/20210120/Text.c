#define _CRT_SECURE_NO_WARNINGS

// Text 1
//在一个有序数组中查找具体的某个数字n。 编写int binsearch(int x, int v[], int n); 功能：在v[0]
//<= v[1] <= v[2] <= …. <= v[n - 1]的数组中查找x
//           ----->              二分查找
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int sz = sizeof (a) / sizeof (a[0]) ;
//	int left=0;
//	int right= sz - 1;
//	int  k =10;
//	while (left <= right) {
//		int mid = left + (right - left) / 2; // 不用 ( left / 2 + right / 2 ) 或者 （（left + right）/ 2 ）
//	 	if (a[mid] < k) {                    //       3/2 + 5/2 == 3                   左值和右值足够大时 可能会溢出 
//			left = mid + 1 ;                 //       会丢失下标                  
//		}
//		else if(a[mid] > k) { 
//			right = mid - 1;
//		}
//		else {
//			printf("找到了，下标为%d\n", mid);
//			break ;
//		}
//		if (left > right) {
//			printf("找不到k:%d\n", k);
//		}
//	}
//	return 0 ;
//}


// Text 2
//编写代码，演示多个字符从两端移动，向中间汇聚。
//
//#include <stdio.h>
//#include <Windows.h>
//#include <string.h>
//
//int main () {
//	char arr1[] = { "欢迎来到猜数游戏" };
//	char arr2[] = { "################" };
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	printf("%s", arr2);
//	while (left <= right) {
//		
//		arr2[left] = arr1[left];
//		left++;
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		right--;
//		arr2[right] = arr1[right];
//
//		left++;
//		right--;
//		Sleep(1000);
//		system("cls");
//		printf("%s\n", arr2);
//
//		
//	}
//
//	return 0;
//}

//Text 3
//实现一个猜数游戏
//#include <stdio.h>
//#include <Windows.h>
//#include <string.h>
//void LED() {
//	char arr1[] = { "欢迎来到猜数游戏" };
//	char arr2[] = { "################" };
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	printf("%s", arr2);
//	while (left <= right) {
//
//		arr2[left] = arr1[left];
//		left++;
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		right--;
//		arr2[right] = arr1[right];
//
//		left++;
//		right--;
//		Sleep(1000);
//		system("cls");
//		printf("%s\n", arr2);
//	}
//}
//
//void MENU() {
//	printf("                   #########################\n");
//	printf("                    ######  1. PLAY   #######\n");
//	printf("                     ########  2. EXIT   #####\n");
//	printf("                      #########################\n");
//}
//
//int main() {
//	LED();
//
//	MENU();
//}