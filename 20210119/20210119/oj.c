#define _CRT_SECURE_NO_WARNINGS
// OJ 1
//��żת��

#include <stdio.h>
int main() {
	char ch;
	while (scanf("%c", &ch) != EOF) {
		getchar();
		if (ch >= 'a' && ch <= 'z') {
			printf("%c\n", ch - 32);
		}
		else if (ch >= 'A' && ch <= 'Z') {
			printf("%c\n", ch + 32);
		}
	}
	return 0;
}

// OJ 2
//�����Ƚ�

#include <stdio.h>
//�����Ƚ�
int twoMax(int a, int b) {
	return a > b ? a : b;
}

//�����Ƚ� ���������Ƚ�ʵ��
int threeMax(int a, int b, int c) {
	return twoMax(twoMax(a, b), c);
}

int main() {
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF) {
		printf("%d\n", threeMax(a, b, c));
	}

}