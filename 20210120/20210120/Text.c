#define _CRT_SECURE_NO_WARNINGS

// Text 1
//��һ�����������в��Ҿ����ĳ������n�� ��дint binsearch(int x, int v[], int n); ���ܣ���v[0]
//<= v[1] <= v[2] <= ��. <= v[n - 1]�������в���x
//           ----->              ���ֲ���
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
//		int mid = left + (right - left) / 2; // ���� ( left / 2 + right / 2 ) ���� ����left + right��/ 2 ��
//	 	if (a[mid] < k) {                    //       3/2 + 5/2 == 3                   ��ֵ����ֵ�㹻��ʱ ���ܻ���� 
//			left = mid + 1 ;                 //       �ᶪʧ�±�                  
//		}
//		else if(a[mid] > k) { 
//			right = mid - 1;
//		}
//		else {
//			printf("�ҵ��ˣ��±�Ϊ%d\n", mid);
//			break ;
//		}
//		if (left > right) {
//			printf("�Ҳ���k:%d\n", k);
//		}
//	}
//	return 0 ;
//}


// Text 2
//��д���룬��ʾ����ַ��������ƶ������м��ۡ�
//
//#include <stdio.h>
//#include <Windows.h>
//#include <string.h>
//
//int main () {
//	char arr1[] = { "��ӭ����������Ϸ" };
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
//ʵ��һ��������Ϸ
//#include <stdio.h>
//#include <Windows.h>
//#include <string.h>
//void LED() {
//	char arr1[] = { "��ӭ����������Ϸ" };
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