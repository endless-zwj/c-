#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

int main()
{
	SListNode* pList = NULL;
	SListPushFront(&pList, 13);
	SListPushFront(&pList, 15);
	SListPushFront(&pList, 18);
	SListPushFront(&pList, 19);
	SListPushFront(&pList, 43);
	PrintSList(pList);

	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	PrintSList(pList);
	return 0;
}