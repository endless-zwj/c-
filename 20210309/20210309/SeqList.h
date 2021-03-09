#pragma once

typedef int SLDataType; // ���Է���  ���и���  ˳����� ���ݴ�ŵ�����
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>

//�ýṹ�嶨��һ��˳��� ----> һ���ṹ����� �Ϳ� ��ʾһ��˳���
typedef struct SeqList
{
	SLDataType* Array;
	int size;         // ��˳������Ч����
	int capacity;     // ˳��������
}SeqList;

//������˳�����е� ��ɾ��� �ķ���

//<1>β��
void SeqListPushBack(SeqList* ps, SLDataType x); // ps ָ�� �豻�޸ĵ�˳���

//<2>βɾ
void SeqListPopBack(SeqList* ps);

//<3>ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x);

//<4>ͷɾ
void SeqListPopFront(SeqList* ps);

//<5>�������
void SeqListInsert(SeqList* ps, int pos, SLDataType x);

//<6>���ɾ��
void SeqListErase(SeqList* ps, int pos);

//<7>����
void SeqListFind(SeqList* ps, SLDataType x);

//<8>��ʼ��˳���
void SeqListInit(SeqList* ps);

//<9>���˳����Ƿ�����
void CheckSeqList(SeqList* ps);

//<10>��ӡ˳���
void PrintSeqList(SeqList* ps);