#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>

//��5
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

//��7
int main()
{
	int a, b;
	printf("������a: ");
	scanf("%d",&a);
	printf("������b: ");
	scanf("%d", &b);
	printf("%d %d\n",(a>b?a:b) ,(a<b?a:b));
	return 0 ;
}

//��8
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
			printf("������array[%d][%d] ", i , j);
			scanf("%d",&array[i][j]);
		}
	}
	system("cls");
	printf("ת��ǰ:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	reverse(array);
	printf("ת�ú�:\n");
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