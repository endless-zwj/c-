#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef int SLDataType ;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SListNode;

//����һ���ڵ�
SListNode* BuySListNode(SLDataType x);

//��ӡ
void PrintSList(SListNode* phead);

//β��
void SListPushBack(SListNode** pphead ,SLDataType x);

//βɾ
void SListPopBack(SListNode** pphead);

//ͷ��
void SListPushFront(SListNode** pphead, SLDataType x);

//ͷɾ
void SListPopFront(SListNode** pphead);