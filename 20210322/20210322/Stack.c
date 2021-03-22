#define _CRT_SECURE_NO_WARNINGS

#include"Stack.h"

//初始化栈
void InitStack(Stack* pStack)
{
	assert(pStack);
	pStack->_top = 0;        //栈内无元素，初始化栈顶位置为零；
	pStack->_capacity = 10;
	pStack->_array = (SDataType*)malloc(sizeof(SDataType)* pStack->_capacity); //先开辟10个空间
}

//打印堆
void PrintStack(Stack* pStack)
{
	int i = 0;
	printf("栈底[");
	for ( i = 0; i < pStack->_top; i++)
	{
		printf(" %d ",pStack->_array[i]);
	}
	printf("]栈顶\n");
}

//入栈(插入元素)
void PushStack(Stack* pStack, SDataType x)
{
	assert(pStack);
	if (pStack->_top == pStack->_capacity)
	{
		pStack->_capacity *= 2 ;
		SDataType* tmp = (SDataType*)realloc(pStack->_array, sizeof(SDataType)* (pStack->_capacity) );
		if (tmp == NULL)
		{
			printf("内存已满!\n");
			exit(-1);
		}
		pStack->_array = tmp;
	}
	pStack->_array[pStack->_top] = x;
	pStack->_top++;
}

//出栈(删除元素)
void PopStack(Stack* pStack)
{
	assert(pStack);
	if (pStack->_top == 0)
	{
		printf("该堆已删空 ");
		return ;
	}
	pStack->_top--;
}

//获取栈顶元素
SDataType  StackTop(Stack* pStack)
{
	assert(pStack);
	if (pStack->_top == 0)
	{
		printf("无数据获取!\n");
		exit(-1);
	}
	return pStack->_array[pStack->_top - 1];
}

//栈的大小
SDataType StackSize(Stack* pStack)
{
	assert(pStack);
	return pStack->_top;
}

//栈是否为空(是返回1，否返回0)
void EmptyStack(Stack* pStack)
{
	assert(pStack);
	if (pStack->_top == 0)
	{
		return 1;
	}
	return 0;
}

//销毁栈
void DestoryStack(Stack* pStack)
{
	assert(pStack);
	free(pStack->_array);
	pStack->_array = NULL;
	pStack->_top = 0;
	pStack->_capacity = 0;
}



