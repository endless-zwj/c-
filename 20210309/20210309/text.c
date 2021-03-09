#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

int main()
{
	SeqList s;
	SeqListInit(&s);  
	SeqListPushBack(&s, 14);
	SeqListPushBack(&s, 13);
	SeqListPushBack(&s, 12);
	SeqListPushBack(&s, 11);
	SeqListPushBack(&s, 15);

	SeqListInsert(&s, 0, 0);
	PrintSeqList(&s);
	SeqListErase(&s, 2);
	PrintSeqList(&s);

	return 0;
}