#define _CRT_SECURE_NO_WARNINGS
#define SDataType char 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef struct Stack
{
	int _top;   // _top表示栈最后一个元素的位置
	SDataType* _array;
	int _capacity;
}Stack;
//初始化栈
void InitStack(Stack* pStack)
{
	assert(pStack);
	pStack->_top = 0;        //栈内无元素，初始化栈顶位置为零；
	pStack->_capacity = 10;
	pStack->_array = (SDataType*)malloc(sizeof(SDataType)* pStack->_capacity); //先开辟10个空间
}
//入栈(插入元素)
void PushStack(Stack* pStack, SDataType x)
{
	assert(pStack);
	if (pStack->_top == pStack->_capacity)
	{
		pStack->_capacity *= 2;
		SDataType* tmp = (SDataType*)realloc(pStack->_array, sizeof(SDataType)* (pStack->_capacity));
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
		exit(1);
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
//栈是否为空(是返回true，否返回false)
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
		//左括号进队列
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