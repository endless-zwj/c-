#define _CRT_SECURE_NO_WARNINGS

#include"Sqlist.h"

SListNode* BuySListNode(SLDataType x)
//����һ���ڵ�
//1.�����ڴ�
//2.data�� ��ֵ
//3.next�� �ÿ�
//4.���ؽڵ�
{
	SListNode* newNode = ((SListNode*)malloc(sizeof(SListNode)));
	if (newNode == NULL)
	{
		printf("�ڴ�����ʧ�ܣ�\n");
		exit(-1);
	}
	newNode->next = NULL;
	newNode->data = x;

	return newNode;
}

//һ��ָ��phead����pListָ��  phead��pList��һ����ʱ���������ܸı�ʵ���ڲ�������
//��ȻҲ�޷��ı�ʵ��nextָ���ָ�򣬴ﲻ�������Ч��
//����pList�޷��ı�ָ��,���������Ѿ���ɲ��룬���������ӡ����
void PrintSList(SListNode* phead)

{
	printf("\n\n\n\n\t\t\t\t");
	while (phead != NULL)
	{
		printf("%d->", phead->data);
		phead = phead->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pphead, SLDataType x)
{
	SListNode* newNode = BuySListNode(x);
	if ((*pphead) == NULL)//�ж��Ƿ���ͷ�ڵ�
	{
		*pphead = newNode;
	}
	else //ѭ���ҵ�β�ڵ�
	{
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;//��β�ϲ���ڵ�

	}
}

void SListPopBack(SListNode** pphead)
{
	if (*pphead == NULL)               //�޽ڵ�
	{
		printf("������Ϊ�գ�\n");
		return;
	}
	else if ((*pphead)->next == NULL) //һ���ڵ�
	{
		free(*pphead);
	}
	else                              //����������   
	{
		SListNode* Next = (*pphead)->next;
		SListNode* Prev = *pphead;
		while (Next->next != NULL)//�ҵ�������һ�͵ڶ����ڵ�
		{						  //�ͷ����һ���������ڶ���next�ÿ�
			Prev = Prev->next;
			Next = Next->next;
		}
		free(Next);
		Prev->next = NULL;
	}
}

void SListPushFront(SListNode** pphead, SLDataType x)
{
	SListNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		newNode->next = *pphead;     //��ͷǰ����ڵ�
		*pphead = newNode;           //�ı�ͷ�ڵ�  
	}
}

void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		printf("������Ϊ�գ�\n");
		return;
	}
	else
	{
		SListNode* cur = *pphead;     //ͷ�ڵ���ƣ����ͷŵ�һ���ڵ�
		*pphead = (*pphead)->next;
		free(cur);
	}
}

int SListSize(SListNode** pphead)
{
	assert(pphead);

	int size = 0;

	SListNode* cur = *pphead;
	while (cur != NULL)
	{
		size++;
		cur = cur->next; 
	}

	return size; 
}

int SListFind(SListNode** pphead, int pos)
{
	assert(pphead);

	assert(SListSize(pphead) >= pos && pos >= 1);
	SListNode* cur = *pphead;
	int start = pos - 1;

	while (start) //�������� pos-1 ��Ԫ��
	{
		cur = cur->next;
		start--;
	}
	return cur->data ;
}

int SListSearchVal(SListNode** pphead, int val)
{
	assert(pphead);

	int index = 1;
	SListNode* cur = *pphead;
	while (cur != NULL)
	{
		if (cur->data == val)
			return index;
		index++;
		cur = cur->next;
	}
	return 0;
}


