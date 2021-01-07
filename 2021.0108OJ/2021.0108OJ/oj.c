#define _CRT_SECURE_NO_WARNINGS
//OJ 1
#include<stdio.h>
int main()
{
	long lcm, gcd, m, n, swap, r, s;
	scanf("%ld %ld", &m, &n);
	if (m<n)
	{
		swap = m;
		m = n;
		n = swap;
	}
	lcm = m*n;
	while (m%n != 0)
	{
		r = m%n;
		m = n;
		n = r;
	}
	gcd = n;
	lcm /= gcd;
	s = gcd + lcm;
	printf("%ld", s);
	return 0;
}

//OJ 2

