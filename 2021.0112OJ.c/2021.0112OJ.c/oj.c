#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//OJ 1
int main()
{
	int i, j = 0, min, n, a[10], b[10], delete, count = 0;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &delete);

	for (i = 0; i<n; i++)
	if (a[i] != delete)
	{
		b[j] = a[i];
		j++;
		count++;
	}
	for (j = 0; j<count; j++)
		printf("%d ", b[j]);

	return 0;
}