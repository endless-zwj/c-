#define _CRT_SECURE_NO_WARNINGS
//OJ 1
#include <stdio.h>
int main()
{
	int N, i, JS = 0, OS = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		if (i % 2 == 1)
			JS++;
		else
			OS++;
	}
	printf("%d %d", JS, OS);
	return 0;
}

//OJ 2
#include <stdio.h>
int main()
{
	float score[100], max, min, aver, swap, sum = 0;
	int i, n;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%f", &score[i]);
	}

	max = min = score[0];
	for (i = 0; i<n; i++)
	{
		if (score[i]>max)
			max = score[i];
		if (score[i]<min)
			min = score[i];
		sum += score[i];
	}

	aver = sum / n;

	printf("%.2f %.2f %.2f", max, min, aver);

	return 0;
}

//OJ 3
#include<stdio.h>
#include<string.h>

int main()
{
	char a1[100];
	char a2[100];
	scanf("%s %s", a1, a2);
	if (strcmp(a1, a2) == 0)
		printf("%s", "same");
	else
		printf("%s", "different");
	return 0;
}
