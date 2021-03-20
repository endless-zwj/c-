#define _CRT_SECURE_NO_WARNINGS

#include"List.h"

//��ʼ��˫������--1.��ͷ�ڵ�����ָ��ָ���Լ�
void InitList(ListNode** pphead)
{
	*pphead = BuyListNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}

//�����ڵ�---- 1.��ֵ 2.�ÿ�����ָ��
ListNode* BuyListNode(ListType x)
{
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	Node->data = x;
	Node->next = NULL;
	Node->prev = NULL;

	return Node;
}

//��ӡ˫������--- 1.�ӵڶ����ڵ㿪ʼ����������,����ӡֵ
void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	//��һ:(������,����ӡЧ���Ϻ�)
	if (cur == phead)
	{
		printf("������Ϊ��!\n");
		return;
	}
	printf(" phead <-> ");
	while (cur != phead)
	{
		printf(" [%d]  <-> ", cur->data);
		cur = cur->next;
	}
	printf("phead\n");

	//����:
	/*while (cur != phead)
	{
		printf(" [%d]  <-> ", cur->data);
		cur = cur->next;
	}
	printf("\n");*/

}

//β��
void ListPushBack(ListNode* phead,ListType x)
{
	assert(phead);
	
	ListNode* newNode = BuyListNode(x);
	ListNode* cur = phead->next;

	//�ҵ�β�ڵ㷽��һ:(��Ϊ����)
	while (cur->next != phead)
	{
		cur = cur->next;
	}
	//�ҵ�β�ڵ㷽������
	//ListNode* tail = phead->prev;

	//˫�����������Ԫ����Ҫ�޸��ĸ�ָ���ָ��
	cur->next = newNode;
	newNode->prev = cur; //δ�Ӵ˴����� βɾ��ɾ�������� ����bug 
	newNode->next = phead;
	phead->prev = newNode;
}

//βɾ
void ListPopBack(ListNode* phead)
{
	ListNode*cur = phead->next;

	if (cur == phead)
	{
		printf("����������Ԫ�ؿ�ɾ!\n");
		return;
	}

	while (cur->next != phead)
	{
		cur = cur->next;
	}
	//βɾ�����ҵ�β�ڵ�ǰһ���ڵ� 
	ListNode* curPrev = cur->prev;
	//�øýڵ�nextָ��ͷ�ڵ�
	curPrev->next = phead;
	//ͷ�ڵ�prevָ����º��β�ڵ�
	phead->prev = curPrev;
	free(cur);
	cur = NULL;
}

//ͷ��
void ListPushFront(ListNode* phead,ListType x)
{
	ListNode* newNode = BuyListNode(x);
	ListNode* cur = phead->next;

	//����ı��ĸ�ָ�����
	phead->next = newNode;
	newNode->next = cur;
	newNode->prev = phead;
	cur->prev = newNode;
}

//ͷɾ
void ListPopFront(ListNode* phead)
{
	ListNode* cur = phead->next;
	if (cur == phead)
	{
		printf("����������Ԫ�ؿ�ɾ!\n");
		return;
	}
	ListNode* curNext = cur->next;
	phead->next = curNext;
	curNext->prev = phead;
}

//����������λ��
ListNode* FindNum(ListNode*  phead, ListType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//ɾ���������Ľڵ�
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

//�ڲ�����ǰһ��λ�ô�����Ԫ��
void ListInsert(ListNode* pos, ListType x)
{
	assert(pos);
	ListNode* newNode = BuyListNode(x);

	ListNode* posPrev = pos->prev;

	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;
}

//�������
void ListClear(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next ;
	}

	phead->next = NULL;
	phead->prev = NULL;

	phead->next = phead;
	phead->prev = phead;
	printf("�����������!\n");
}

//��������
void ListDestory(ListNode** pphead)
{
	assert(pphead);

	ListClear(*pphead);

	free(*pphead);
	*pphead = NULL;
}


