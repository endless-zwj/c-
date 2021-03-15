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
		printf("ͨѶ¼Ϊ��!\n");
		printf("-----------------------------------\n");
	}
	else
	{
		printf("\n");
		printf("\n");
		printf("-----------------------------------\n");
		printf("%-10s\t %-10s\t %-11s\n", "����", "�Ա�", "�绰����");
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
		printf("ͨѶ¼����!\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", (con->data[con->size].name) );  //���ﲻ��&��������name/sex/numberΪ�ַ�����
		printf("�������Ա�:>");
		scanf("%s", (con->data[con->size].sex));
		printf("������绰����:>");
		scanf("%s", (con->data[con->size].number));
		printf("�ѱ�����ϵ����Ϣ!\n");
		con->size++;
	}
}

static int FindName(Contact* con)
{
	int i;
	char str[10];
	printf("������Ҫ���ҵ�����:>");
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
		printf("���޴��ˣ�\n");
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
		printf("ɾ���ɹ���\n");
		printf("\n");
		con->size--;
	}
}

void Search(Contact* con)
{
	int pos = FindName(con);
	if (pos == -1)
	{
		printf("���޴��ˣ�\n");
		return ;
	}
	else
	{
		printf("��������Ϣ����:\n");
		printf("����:%s\n",con->data[pos].name);
		printf("�Ա�:%s\n",con->data[pos].sex);
		printf("�绰����:%s\n",con->data[pos].number);
	}
	return ;
}
void Modify(Contact* con)
{
	int pos = FindName(con);
	printf("���޸�����:> ");
	scanf("%s",con->data[pos].name);
	printf("���޸��Ա�:> ");
	scanf("%s", con->data[pos].sex);
	printf("���޸ĵ绰����:> ");
	scanf("%s", con->data[pos].number);
}

int cmp_by_name(const void* e1,const void* e2)
{
	int val= strcmp( ((PhoneList*)e1)->name, ((PhoneList*)e2)->name);
	return val;
}