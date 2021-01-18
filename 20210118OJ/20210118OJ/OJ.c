#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int score;
	while ((scanf("%d", &score)) != EOF) {
		if (score >= 60) {
			printf("Pass\n");
		}
		else {
			printf("Fail\n");
		}
	}
	return 0;
}
