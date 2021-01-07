#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n, t, i, count = 0, s = 0;
	scanf("%d", &n);
	for (i = (n - 12); i >= 0; i -= 12)
		count++;
	s = count * 4;
	s += 2;
	printf("%d", s);
	return 0;
}
