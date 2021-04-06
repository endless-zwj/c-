#define _CRT_SECURE_NO_WARNINGS

#include"Sqlist.h"

SListNode* BuySListNode(SLDataType x)
//创建一个节点
//1.分配内存
//2.data区 赋值
//3.next区 置空
//4.返回节点
{
	SListNode* newNode = ((SListNode*)malloc(sizeof(SListNode)));
	if (newNode == NULL)
	{
		printf("内存申请失败！\n");
		exit(-1);
	}
	newNode->next = NULL;
	newNode->data = x;

	return newNode;
}

//一级指针phead接收pList指针  phead是pList的一份临时拷贝，不能改变实参内部的内容
//自然也无法改变实参next指针的指向，达不到插入的效果
//最终pList无法改变指向,但若链表已经完成插入，其可用来打印链表
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
	if ((*pphead) == NULL)//判断是否有头节点
	{
		*pphead = newNode;
	}
	else //循环找到尾节点
	{
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;//在尾上插入节点

	}
}

void SListPopBack(SListNode** pphead)
{
	if (*pphead == NULL)               //无节点
	{
		printf("该链表为空！\n");
		return;
	}
	else if ((*pphead)->next == NULL) //一个节点
	{
		free(*pphead);
	}
	else                              //两个及以上   
	{
		SListNode* Next = (*pphead)->next;
		SListNode* Prev = *pphead;
		while (Next->next != NULL)//找到倒数第一和第二个节点
		{						  //释放最后一个，倒数第二个next置空
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
		newNode->next = *pphead;     //在头前插入节点
		*pphead = newNode;           //改变头节点  
	}
}

void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		printf("该链表为空！\n");
		return;
	}
	else
	{
		SListNode* cur = *pphead;     //头节点后移，并释放第一个节点
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

	while (start) //往后跳过 pos-1 个元素
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


