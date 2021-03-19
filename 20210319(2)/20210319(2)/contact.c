#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void InitContact(Contact* con)
{

	con->size = 0;//��ʼ��ͨѶ¼������Ϊ��
	con->capacity = 2;
	con->data = (PhoneList*)malloc(sizeof(PhoneList)* con->capacity);
	if (con->data == NULL)
	{
		printf("ͨѶ¼����ʧ��!\n");
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
		printf("ͨѶ¼�ѱ���!\n");
		fclose(pfOut);
		pfOut = NULL;
	}
}


int Dilatation(Contact* con)//����
{
	PhoneList* ptr = (PhoneList*)realloc(con->data, sizeof(PhoneList)* con->capacity * 2);
	if (ptr != NULL)
	{
		con->capacity *= 2;  //������ݳɹ��������ӱ�
		con->data = ptr;     //��ptrָ����ǿ�ռ佻��con->data;ԭ���Ŀռ䱻�ͷ�
		printf("���ݳɹ�!\n");
		return 1;
	}
	else
	{
		printf("����ʧ��!\n");
		return 0;
	}
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
		for (i = 0; i < con->size; i++)//���δ�ӡ��ϵ����Ϣ
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
			printf("�ڴ�����,�޷����!\n");
			printf("�����˳�ͨѶ¼!\n");
			SaveContact(con);
			exit(1);
		}
	}
	//ֱ����data[con->size]�������ϵ����Ϣ
	printf("����������:>");
	scanf("%s", (con->data[con->size].name));  //���ﲻ��&��������name/sex/numberΪ�ַ�����
	printf("�������Ա�:>");
	scanf("%s", (con->data[con->size].sex));
	printf("������绰����:>");
	scanf("%s", (con->data[con->size].number));
	printf("�ѱ�����ϵ����Ϣ!\n");
	con->size++;//����һ�Σ���ϵ��+1
}

static int FindName(Contact* con)
{
	int i;
	char str[10];
	printf("������Ҫ���ҵ�����:>");
	scanf("%s", str);
	for (i = 0; i < con->size; i++)
	{
		if (strcmp(con->data[i].name, str) == 0)
			return i;
	}
	return -1;
}//������ϵ�ˣ��޸���ϵ�ˣ�ɾ����ϵ�˶�Ҫ���Ҹ��������±�
//��װ����FindName�ܷ�ֹ��������

void DelContact(Contact* con)
{
	//˳����ɾ���������ڴ渲����ʵ�ֵ�
	//���Ѻ������ݸ�������ǰ������
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
		//ɾ��һ�� ��ϵ��-1
	}

}

void Search(Contact* con)
{
	int pos = FindName(con);
	if (pos == -1)
	{
		printf("���޴��ˣ�\n");
		return;
	}
	else
	{
		printf("��������Ϣ����:\n");
		printf("����:%s\n", con->data[pos].name);
		printf("�Ա�:%s\n", con->data[pos].sex);
		printf("�绰����:%s\n", con->data[pos].number);
	}
	return;
}
void Modify(Contact* con)
{
	int pos = FindName(con);
	//ͨ��FindName�ҵ����޸��˵��±֮꣬��ֱ�Ӷ�������±��ڵ������޸�
	printf("���޸�����:> ");
	scanf("%s", con->data[pos].name);
	printf("���޸��Ա�:> ");
	scanf("%s", con->data[pos].sex);
	printf("���޸ĵ绰����:> ");
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
	printf("ͨѶ¼�����!\n");
}
