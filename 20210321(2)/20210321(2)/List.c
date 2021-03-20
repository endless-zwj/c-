#define _CRT_SECURE_NO_WARNINGS

#include"List.h"

//初始化双向链表--1.让头节点两个指针指向自己
void InitList(ListNode** pphead)
{
	*pphead = BuyListNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}

//创建节点---- 1.赋值 2.置空两个指针
ListNode* BuyListNode(ListType x)
{
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	Node->data = x;
	Node->next = NULL;
	Node->prev = NULL;

	return Node;
}

//打印双向链表--- 1.从第二个节点开始，遍历链表,并打印值
void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	//法一:(较冗余,但打印效果较好)
	if (cur == phead)
	{
		printf("该链表为空!\n");
		return;
	}
	printf(" phead <-> ");
	while (cur != phead)
	{
		printf(" [%d]  <-> ", cur->data);
		cur = cur->next;
	}
	printf("phead\n");

	//法二:
	/*while (cur != phead)
	{
		printf(" [%d]  <-> ", cur->data);
		cur = cur->next;
	}
	printf("\n");*/

}

//尾插
void ListPushBack(ListNode* phead,ListType x)
{
	assert(phead);
	
	ListNode* newNode = BuyListNode(x);
	ListNode* cur = phead->next;

	//找到尾节点方法一:(较为冗余)
	while (cur->next != phead)
	{
		cur = cur->next;
	}
	//找到尾节点方法二：
	//ListNode* tail = phead->prev;

	//双向链表插入新元素需要修改四个指针的指向
	cur->next = newNode;
	newNode->prev = cur; //未加此处导致 尾删和删除查找数 发生bug 
	newNode->next = phead;
	phead->prev = newNode;
}

//尾删
void ListPopBack(ListNode* phead)
{
	ListNode*cur = phead->next;

	if (cur == phead)
	{
		printf("该链表已无元素可删!\n");
		return;
	}

	while (cur->next != phead)
	{
		cur = cur->next;
	}
	//尾删需先找到尾节点前一个节点 
	ListNode* curPrev = cur->prev;
	//让该节点next指向头节点
	curPrev->next = phead;
	//头节点prev指向更新后的尾节点
	phead->prev = curPrev;
	free(cur);
	cur = NULL;
}

//头插
void ListPushFront(ListNode* phead,ListType x)
{
	ListNode* newNode = BuyListNode(x);
	ListNode* cur = phead->next;

	//插入改变四个指针变量
	phead->next = newNode;
	newNode->next = cur;
	newNode->prev = phead;
	cur->prev = newNode;
}

//头删
void ListPopFront(ListNode* phead)
{
	ListNode* cur = phead->next;
	if (cur == phead)
	{
		printf("该链表已无元素可删!\n");
		return;
	}
	ListNode* curNext = cur->next;
	phead->next = curNext;
	curNext->prev = phead;
}

//查找数所在位置
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

//删除查找数的节点
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

//在查找数前一个位置处插入元素
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

//清空链表
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
	printf("该链表，已清空!\n");
}

//销毁链表
void ListDestory(ListNode** pphead)
{
	assert(pphead);

	ListClear(*pphead);

	free(*pphead);
	*pphead = NULL;
}


