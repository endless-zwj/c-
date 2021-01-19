#define _CRT_SECURE_NO_WARNINGS
// OJ 1
//奇偶转换

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
//三数比较

#include <stdio.h>
//两数比较
int twoMax(int a, int b) {
	return a > b ? a : b;
}

//三数比较 调用两数比较实现
int threeMax(int a, int b, int c) {
	return twoMax(twoMax(a, b), c);
}

int main() {
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF) {
		printf("%d\n", threeMax(a, b, c));
	}

}