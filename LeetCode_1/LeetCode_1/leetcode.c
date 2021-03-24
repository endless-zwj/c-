#define _CRT_SECURE_NO_WARNINGS
#define SDataType char 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef struct Stack
{
	int _top;   // _top��ʾջ���һ��Ԫ�ص�λ��
	SDataType* _array;
	int _capacity;
}Stack;
//��ʼ��ջ
void InitStack(Stack* pStack)
{
	assert(pStack);
	pStack->_top = 0;        //ջ����Ԫ�أ���ʼ��ջ��λ��Ϊ�㣻
	pStack->_capacity = 10;
	pStack->_array = (SDataType*)malloc(sizeof(SDataType)* pStack->_capacity); //�ȿ���10���ռ�
}
//��ջ(����Ԫ��)
void PushStack(Stack* pStack, SDataType x)
{
	assert(pStack);
	if (pStack->_top == pStack->_capacity)
	{
		pStack->_capacity *= 2;
		SDataType* tmp = (SDataType*)realloc(pStack->_array, sizeof(SDataType)* (pStack->_capacity));
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
		exit(1);
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
//ջ�Ƿ�Ϊ��(�Ƿ���true���񷵻�false)
bool EmptyStack(Stack* pStack)
{
	assert(pStack);
	if (pStack->_top == 0)
	{
		return true;
	}
	return false;
}

bool isValid(char * s){
	Stack st;
	InitStack(&st);
	int ret = 0;
	while (*s != '\0')
	{
		//�����Ž�����
		if (*s == '(' || *s == '[' || *s == '{')
			PushStack(&st, *s);
		else
		{
			if (EmptyStack(&st))
			{
				ret = false;
				break;
			}
			if (*s == ')' && StackTop(&st) != '(')
			{
				ret = false;
				break;
			}
			if (*s == '}' && StackTop(&st) != '{')
			{
				ret = false;
				break;
			}
			if (*s == ']' && StackTop(&st) != '[')
			{
				ret = false;
				break;
			}
			PopStack(&st);
		}
		++s;
	}
	if (*s == '\0')
		ret = (EmptyStack(&st));
	return ret;
}

int main()
{
	char *s = "([{]";
	bool ret = isValid(s);
	if (ret == true)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	return 0;
}