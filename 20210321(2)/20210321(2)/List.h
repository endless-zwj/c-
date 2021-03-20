#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//˫���ͷ�ڵ�����
#define ListType int 

typedef struct ListNode
{
	ListType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

//��ʼ������
void InitList(ListNode** pphead) ;
//�����ڵ�
ListNode* BuyListNode(ListType x);
//��ӡ˫������
void ListPrint(ListNode* phead);
//β��
void ListPushBack(ListNode* phead,ListType x);
//βɾ
void ListPopBack(ListNode* phead);
//ͷ��
void ListPushFront(ListNode* phead,ListType x);
//ͷɾ
void ListPopFront(ListNode* phead);
//��������
ListNode* FindNum(ListNode* phead,ListType x);
//�ڲ�����ǰ����ڵ�
void ListInsert(ListNode* pos, ListType x);
//ɾ����������Ӧ�Ľڵ�
void ListErase(ListNode* phead);
//�������
void ListClear(ListNode* phead);
//����˫������
void ListDestroy(ListNode** pphead);

