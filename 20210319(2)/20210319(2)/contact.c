#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void InitContact(Contact* con)
{

	con->size = 0;//初始化通讯录内人数为零
	con->capacity = 2;
	con->data = (PhoneList*)malloc(sizeof(PhoneList)* con->capacity);
	if (con->data == NULL)
	{
		printf("通讯录开辟失败!\n");
		exit(1);
	}
	LoadContact(con);
}

void  LoadContact(Contact* con)
{
	FILE* pfIn = fopen("contact.txt", "rb");
	if (pfIn == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	else
	{
		PhoneList tmp = { 0 };
		while (fread(&tmp, sizeof(PhoneList), 1, pfIn))
		{
			if (con->size == con->capacity)
			{
				int ret = Dilatation(con);
			}
			con->data[con->size] = tmp;
			con->size++;
		}
	}
	fclose(pfIn);
	pfIn = NULL;
}


void SaveContact(Contact* con)
{
	FILE* pfOut = fopen("contact.txt", "wb");
	if (pfOut == NULL)
	{
		printf("savaContact::%s\n", strerror(errno));
		return;
	}
	else
	{
		for (int i = 0; i < con->size; i++)
		{
			fwrite(con->data + i, sizeof(PhoneList), 1, pfOut);
		}
		printf("通讯录已保存!\n");
		fclose(pfOut);
		pfOut = NULL;
	}
}


int Dilatation(Contact* con)//扩容
{
	PhoneList* ptr = (PhoneList*)realloc(con->data, sizeof(PhoneList)* con->capacity * 2);
	if (ptr != NULL)
	{
		con->capacity *= 2;  //如果扩容成功，容量加倍
		con->data = ptr;     //将ptr指向的那块空间交给con->data;原来的空间被释放
		printf("扩容成功!\n");
		return 1;
	}
	else
	{
		printf("扩容失败!\n");
		return 0;
	}
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
		for (i = 0; i < con->size; i++)//依次打印联系人信息
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
	if (con->size == con->capacity)
	{
		int ret = Dilatation(con);
		if (ret == 0)
		{
			printf("内存已满,无法添加!\n");
			printf("正在退出通讯录!\n");
			SaveContact(con);
			exit(1);
		}
	}
	//直接在data[con->size]内添加联系人信息
	printf("请输入姓名:>");
	scanf("%s", (con->data[con->size].name));  //这里不用&操作符；name/sex/number为字符数组
	printf("请输入性别:>");
	scanf("%s", (con->data[con->size].sex));
	printf("请输入电话号码:>");
	scanf("%s", (con->data[con->size].number));
	printf("已保存联系人信息!\n");
	con->size++;//插入一次，联系人+1
}

static int FindName(Contact* con)
{
	int i;
	char str[10];
	printf("请输入要查找的姓名:>");
	scanf("%s", str);
	for (i = 0; i < con->size; i++)
	{
		if (strcmp(con->data[i].name, str) == 0)
			return i;
	}
	return -1;
}//查找联系人，修改联系人，删除联系人都要查找该人所在下标
//封装函数FindName能防止代码冗余

void DelContact(Contact* con)
{
	//顺序表的删除都是用内存覆盖来实现的
	//即把后面数据覆盖数组前面数据
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
		//删除一个 联系人-1
	}

}

void Search(Contact* con)
{
	int pos = FindName(con);
	if (pos == -1)
	{
		printf("查无此人！\n");
		return;
	}
	else
	{
		printf("查找人信息如下:\n");
		printf("姓名:%s\n", con->data[pos].name);
		printf("性别:%s\n", con->data[pos].sex);
		printf("电话号码:%s\n", con->data[pos].number);
	}
	return;
}
void Modify(Contact* con)
{
	int pos = FindName(con);
	//通过FindName找到需修改人的下标，之后直接对数组改下标内的内容修改
	printf("请修改姓名:> ");
	scanf("%s", con->data[pos].name);
	printf("请修改性别:> ");
	scanf("%s", con->data[pos].sex);
	printf("请修改电话号码:> ");
	scanf("%s", con->data[pos].number);
}

int cmp_by_name(const void* e1, const void* e2)
{
	int val = strcmp(((PhoneList*)e1)->name, ((PhoneList*)e2)->name);
	return val;
}


void ClearContact(Contact* con)
{
	con->size = 0;
	con->capacity = 0;
	free(con->data);
	con->data = NULL;
	printf("通讯录已清空!\n");
}
