#define _CRT_SECURE_NO_WARNINGS
//OJ 1
#include <stdio.h>
int main()
{
	int hour, min, k;
	scanf("%d:%d", &hour, &min);
	scanf("%d", &k);
	hour += k / 60;
	min += k % 60;
	if (min >= 60)
	{
		hour++;
		min -= 60;
	}
	while (hour >= 24)
		hour -= 24;
	printf("%02d:%02d", hour, min);
	return 0;
}
