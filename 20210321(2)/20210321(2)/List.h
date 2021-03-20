#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//双向带头节点链表
#define ListType int 

typedef struct ListNode
{
	ListType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

//初始化链表
void InitList(ListNode** pphead) ;
//创建节点
ListNode* BuyListNode(ListType x);
//打印双向链表
void ListPrint(ListNode* phead);
//尾插
void ListPushBack(ListNode* phead,ListType x);
//尾删
void ListPopBack(ListNode* phead);
//头插
void ListPushFront(ListNode* phead,ListType x);
//头删
void ListPopFront(ListNode* phead);
//查找数据
ListNode* FindNum(ListNode* phead,ListType x);
//在查找数前插入节点
void ListInsert(ListNode* pos, ListType x);
//删除查找数对应的节点
void ListErase(ListNode* phead);
//清空链表
void ListClear(ListNode* phead);
//销毁双向链表
void ListDestroy(ListNode** pphead);

