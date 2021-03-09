#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

void SeqListInit(SeqList* ps) // Ä¬ÈÏ³õÊ¼ÈÝÁ¿ÎªËÄ
{
	ps->Array = (SLDataType*)malloc(sizeof(SLDataType)*4);

	if (ps->Array == NULL) //ÉêÇëÄÚ´æÊ§°Ü
	{
		printf("ÉêÇëÄÚ´æÊ§°Ü\n");
		exit(-1);
	}

	ps->size = 0;
	ps->capacity = 4;
}

void CheckSeqList(SeqList* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		ps->capacity *= 2;
		ps->Array = (SLDataType*)realloc(ps->Array ,sizeof(SLDataType)*ps->capacity );
		if (ps->Array == NULL)
		{
			printf("À©ÈÝÊ§°Ü\n");
			exit(-1);
		}
	}
}

void PrintSeqList(SeqList* ps)
{
	assert(ps);
	int i;
	for ( i = 0; i < ps->size; ++i)
	{
		printf("%d ",ps->Array[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckSeqList(ps);
	ps->Array[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}

void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckSeqList(ps);
	int movePos = ps->size - 1;
	while (movePos >= 0)//ÒÆÎ»
	{
		ps->Array[movePos + 1] = ps->Array[movePos];
		movePos--;
	}
	ps->Array[0] = x;  //²åÈë
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	int start = 0;
	while (start < ps->size - 1)
	{
		ps->Array[start] = ps->Array[start + 1];
		start++;
	}
	ps->size--;
}

void SeqListInsert(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	CheckSeqList(ps);
	int end = ps->size - 1; 
	for (end; end >= pos; --end)  //°üº¬Í·²åºÍÎ²²å
	{
		ps->Array[end + 1] = ps->Array[end];
	}
	ps->Array[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int start = pos;
	while (start <= ps->size - 1)
	{
		ps->Array[start] = ps->Array[start + 1];
		start++;
	}
	ps->size--;
}

int SeqListFind(SeqList* ps ,SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->Array[i] == x)
		{
			return i;
		}
	}
	return -1;
}