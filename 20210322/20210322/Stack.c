#define _CRT_SECURE_NO_WARNINGS

#include"Stack.h"

//��ʼ��ջ
void InitStack(Stack* pStack)
{
	assert(pStack);
	pStack->_top = 0;        //ջ����Ԫ�أ���ʼ��ջ��λ��Ϊ�㣻
	pStack->_capacity = 10;
	pStack->_array = (SDataType*)malloc(sizeof(SDataType)* pStack->_capacity); //�ȿ���10���ռ�
}

//��ӡ��
void PrintStack(Stack* pStack)
{
	int i = 0;
	printf("ջ��[");
	for ( i = 0; i < pStack->_top; i++)
	{
		printf(" %d ",pStack->_array[i]);
	}
	printf("]ջ��\n");
}

//��ջ(����Ԫ��)
void PushStack(Stack* pStack, SDataType x)
{
	assert(pStack);
	if (pStack->_top == pStack->_capacity)
	{
		pStack->_capacity *= 2 ;
		SDataType* tmp = (SDataType*)realloc(pStack->_array, sizeof(SDataType)* (pStack->_capacity) );
		if (tmp == NULL)
		{
			printf("�ڴ�����!\n");
			exit(-1);
		}
		pStack->_array = tmp;
	}
	pStack->_array[pStack->_top] = x;
	pStack->_top++;
}

//��ջ(ɾ��Ԫ��)
void PopStack(Stack* pStack)
{
	assert(pStack);
	if (pStack->_top == 0)
	{
		printf("�ö���ɾ�� ");
		return ;
	}
	pStack->_top--;
}

//��ȡջ��Ԫ��
SDataType  StackTop(Stack* pStack)
{
	assert(pStack);
	if (pStack->_top == 0)
	{
		printf("�����ݻ�ȡ!\n");
		exit(-1);
	}
	return pStack->_array[pStack->_top - 1];
}

//ջ�Ĵ�С
SDataType StackSize(Stack* pStack)
{
	assert(pStack);
	return pStack->_top;
}

//ջ�Ƿ�Ϊ��(�Ƿ���1���񷵻�0)
void EmptyStack(Stack* pStack)
{
	assert(pStack);
	if (pStack->_top == 0)
	{
		return 1;
	}
	return 0;
}

//����ջ
void DestoryStack(Stack* pStack)
{
	assert(pStack);
	free(pStack->_array);
	pStack->_array = NULL;
	pStack->_top = 0;
	pStack->_capacity = 0;
}



