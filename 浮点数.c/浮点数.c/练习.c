#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n = 9;
	float*p = (float*)&n;
	printf("%f\n", *p);
	return 0;
}

