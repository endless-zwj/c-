#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

void InitContact(Contact* con)
{
	con->size = 0;
	memset(con->data, 0, sizeof(con->data));
}


void Show(Contact* con)
{
	int i = 0;
	if (con->size == 0)
	{
		printf("-----------------------------------\n");
		printf("通讯录为空!\n");
		printf("-----------------------------------\n");
	}
	else
	{
		printf("\n");
		printf("\n");
		printf("-----------------------------------\n");
		printf("%-10s\t %-10s\t %-11s\n", "姓名", "性别", "电话号码");
		for (i = 0; i < con->size; i++)
		{
			printf("%-10s\t %-10s\t %-11s\n", (con->data[i]).name, (con->data[i]).sex, (con->data[i]).number);
		}
		printf("-----------------------------------\n");
		printf("\n");
		printf("\n");
	}
	
}

void AddContact(Contact* con)
{
	if (con->size == Max_phoList)
	{
		printf("通讯录已满!\n");
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", (con->data[con->size].name) );  //这里不用&操作符；name/sex/number为字符数组
		printf("请输入性别:>");
		scanf("%s", (con->data[con->size].sex));
		printf("请输入电话号码:>");
		scanf("%s", (con->data[con->size].number));
		printf("已保存联系人信息!\n");
		con->size++;
	}
}

static int FindName(Contact* con)
{
	int i;
	char str[10];
	printf("请输入要查找的姓名:>");
	scanf("%s",str);
	for (i = 0; i < con->size; i++)
	{
		if (strcmp(con->data[i].name, str) == 0)
			return i;
	}
	return -1;
}

void DelContact(Contact* con)
{
	int pos = FindName(con);
	if (pos == -1)
	{
		printf("查无此人！\n");
		return;
	}
	else
	{
		int i = pos;
		for (i = pos; i < con->size - 1; i++)
		{
			con->data[i] = con->data[i + 1];
		}
		printf("\n");
		printf("删除成功！\n");
		printf("\n");
		con->size--;
	}
}

void Search(Contact* con)
{
	int pos = FindName(con);
	if (pos == -1)
	{
		printf("查无此人！\n");
		return ;
	}
	else
	{
		printf("查找人信息如下:\n");
		printf("姓名:%s\n",con->data[pos].name);
		printf("性别:%s\n",con->data[pos].sex);
		printf("电话号码:%s\n",con->data[pos].number);
	}
	return ;
}
void Modify(Contact* con)
{
	int pos = FindName(con);
	printf("请修改姓名:> ");
	scanf("%s",con->data[pos].name);
	printf("请修改性别:> ");
	scanf("%s", con->data[pos].sex);
	printf("请修改电话号码:> ");
	scanf("%s", con->data[pos].number);
}

int cmp_by_name(const void* e1,const void* e2)
{
	int val= strcmp( ((PhoneList*)e1)->name, ((PhoneList*)e2)->name);
	return val;
}