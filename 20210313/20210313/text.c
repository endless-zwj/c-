#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"


enum Func
{
	Exit,
	addContact,
	delContact,
	serch,
	modify,
	show,
	sort
};


int main()
{
	Contact con;
	InitContact(&con);
	int input;
	do
	{
		printf("************************************\n");
		printf("** 1.addContact  *   2.delContact **\n");
		printf("** 3.serch       *   4.modify     **\n");
		printf("** 5.show        *   6.sort       **\n");
		printf("***********    0.Exit    ***********\n");
		printf("************************************\n");
		printf("请输入你的操作:> ");
		scanf("%d",&input);
		switch (input)
		{
		case addContact:
			AddContact(&con);
			break;
		case delContact:
			DelContact(&con);
			break;
		case serch:
			Search(&con);
			break;
		case show:
			Show(&con);
			break;
		case modify:
			Modify(&con);
		case sort:
			qsort(con.data, sizeof(con.data) / sizeof(con.data[0]), sizeof(con.data[0]), cmp_by_name);
			break;
		case Exit:
			printf("正在退出\n");
		}
	}
	while (input);
}
