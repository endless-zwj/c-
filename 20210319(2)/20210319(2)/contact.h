#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define Max_name 10
#define Max_sex 10
#define Max_number 11
#define Max_phoList 1000

typedef struct PhoneList
{
	char name[Max_name];
	char sex[Max_sex];
	char number[Max_number];
}PhoneList;

typedef struct Contact
{
	PhoneList* data;
	int size;
	int capacity;
} Contact;

//初始化通讯录
void InitContact(Contact* con);
//通讯录扩容
int Dilatation(Contact* con);
//打印通讯录
void Show(Contact* con);
//添加联系人信息
void AddContact(Contact* con);
//删除联系人信息
void DelContact(Contact* con);
//查找联系人
void Search(Contact* con);
//修改指定联系人信息
void Modify(Contact* con);
//对联系人按年龄排序
void Sort(Contact* con);
//用qsort排序时需调用的函数
int cmp_by_name(const void* e1, const void*e2);
//保存通讯录
void SaveContact(Contact* con);
//加载通讯录
void LoadContact(Contact* con);
//清空通讯录
void ClearContact(Contact* con);