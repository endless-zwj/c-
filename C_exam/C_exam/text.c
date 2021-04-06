#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>

//Àý5
int Max_by_two(int a, int b)
{
	return a > b ? a : b;
}

int Max_by_four(int a, int b, int c, int d)
{
	return Max_by_two(Max_by_two(a, b), Max_by_two(c, d));
}


int main()
{
	int a, b, c, d;
	scanf("%d",&a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);

	printf("%d\n",Max_by_four(a,b,c,d));
	return 0 ;  
}

//Àý7
int main()
{
	int a, b;
	printf("ÇëÊäÈëa: ");
	scanf("%d",&a);
	printf("ÇëÊäÈëb: ");
	scanf("%d", &b);
	printf("%d %d\n",(a>b?a:b) ,(a<b?a:b));
	return 0 ;
}

//Àý8
void reverse(int array[3][3])
{
	int tmp = array[0][1]; array[0][1] = array[1][0]; array[1][0] = tmp;
	    tmp = array[2][0]; array[2][0] = array[0][2]; array[0][2] = tmp;
		tmp = array[2][1]; array[2][1] = array[1][2]; array[1][2] = tmp;
}
int main()
{
	int i, j;
	int array[3][3];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("ÇëÊäÈëarray[%d][%d] ", i , j);
			scanf("%d",&array[i][j]);
		}
	}
	system("cls");
	printf("×ªÖÃÇ°:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	reverse(array);
	printf("×ªÖÃºó:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	return 0;
}