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

//��ʼ��ͨѶ¼
void InitContact(Contact* con);
//ͨѶ¼����
int Dilatation(Contact* con);
//��ӡͨѶ¼
void Show(Contact* con);
//�����ϵ����Ϣ
void AddContact(Contact* con);
//ɾ����ϵ����Ϣ
void DelContact(Contact* con);
//������ϵ��
void Search(Contact* con);
//�޸�ָ����ϵ����Ϣ
void Modify(Contact* con);
//����ϵ�˰���������
void Sort(Contact* con);
//��qsort����ʱ����õĺ���
int cmp_by_name(const void* e1, const void*e2);
//����ͨѶ¼
void SaveContact(Contact* con);
//����ͨѶ¼
void LoadContact(Contact* con);
//���ͨѶ¼
void ClearContact(Contact* con);