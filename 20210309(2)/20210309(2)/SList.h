#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef int SLDataType ;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SListNode;

//创建一个节点
SListNode* BuySListNode(SLDataType x);

//打印
void PrintSList(SListNode* phead);

//尾插
void SListPushBack(SListNode** pphead ,SLDataType x);

//尾删
void SListPopBack(SListNode** pphead);

//头插
void SListPushFront(SListNode** pphead, SLDataType x);

//头删
void SListPopFront(SListNode** pphead);