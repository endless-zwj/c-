#pragma once

// stack --堆(LIFO)后进先出

#define SDataType int 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Stack
{
	SDataType _top;   // _top表示栈最后一个元素的位置
	SDataType* _array;
	int _capacity;
}Stack;

//初始化栈
void InitStack(Stack* pStack);

//打印堆
void PrintStack(Stack* pStack);

//入栈(插入元素)
void PushStack(Stack* pStack ,SDataType x);

//出栈(删除元素)
void PopStack(Stack* pStack);

//清空栈(释放空间)
void EmptyStack(Stack* pStack);

//销毁栈
void DestoryStack(Stack* pStack);

//栈的大小
SDataType StackSize(Stack* pStack);

//获取栈顶元素
SDataType StackTop(Stack* pStack);

