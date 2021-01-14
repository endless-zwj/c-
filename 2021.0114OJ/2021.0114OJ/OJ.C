#define _CRT_SECURE_NO_WARNINGS

//OJ 1
#include <stdio.h>
#include <math.h>
int main()
{
	float a, b, c;
	float circumference;
	double area;
	scanf("%f%f%f", &a, &b, &c);
	circumference = a + b + c;
	float p = (a + b + c) / 2.0;
	area = sqrt(p*(p - a)*(p - b)*(p - c));
	printf("circumference=%.2f area=%.2f", circumference, area);
	return 0;
}
