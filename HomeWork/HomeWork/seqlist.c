#define _CRT_SECURE_NO_WARNINGS
#include"Seqlist.h"

void SeqListInit(SeqList* ps) // 默认初始容量为四
{
	ps->Array = (SLDataType*)malloc(sizeof(SLDataType)* 4);

	if (ps->Array == NULL) //申请内存失败
	{
		printf("申请内存失败\n");
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
		ps->Array = (SLDataType*)realloc(ps->Array, sizeof(SLDataType)*ps->capacity);
		if (ps->Array == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
	}
}

void PrintSeqList(SeqList* ps)
{
	assert(ps);
	int i;
	printf("\n\n\n\n\t\t\t\t");
	for (i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->Array[i]);
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
	while (movePos >= 0)//移位
	{
		ps->Array[movePos + 1] = ps->Array[movePos];
		movePos--;
	}
	ps->Array[0] = x;  //插入
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
	//从使用者角度考虑,顺序表下标从1开始
	assert(pos >= 1 && pos <= ps->size+1 );
	CheckSeqList(ps);
	int end = ps->size - 1;
	for (end; end >= pos - 1 ; --end)  //包含头插和尾插
	{
		ps->Array[end + 1] = ps->Array[end];
	}
	ps->Array[pos-1] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos >= 1 && pos <= ps->size);
	int start = pos - 1;
	while (start < ps->size - 1)
	{
		ps->Array[start] = ps->Array[start + 1];
		start++;
	}
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->Array[i] == x)
		{
			//返回数组元素下标加一
			return i+1;
		}
	}
	return -1;
}
