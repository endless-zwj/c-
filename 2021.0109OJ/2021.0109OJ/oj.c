#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
int main()
{
	int n, i, m, s;
	scanf("%d", &n);
	for (i = 0; i<9; i++)
	{
		m = n % 10;
		if (m % 2 == 0)
		{
			m = 0;
		}
		else
		{
			m = 1;
		}
		n = n / 10;
		s = s + m*pow(10, i);
	}
	printf("%d", s);
	return 0;
}