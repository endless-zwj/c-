#pragma once

// stack --��(LIFO)����ȳ�

#define SDataType int 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Stack
{
	SDataType _top;   // _top��ʾջ���һ��Ԫ�ص�λ��
	SDataType* _array;
	int _capacity;
}Stack;

//��ʼ��ջ
void InitStack(Stack* pStack);

//��ӡ��
void PrintStack(Stack* pStack);

//��ջ(����Ԫ��)
void PushStack(Stack* pStack ,SDataType x);

//��ջ(ɾ��Ԫ��)
void PopStack(Stack* pStack);

//���ջ(�ͷſռ�)
void EmptyStack(Stack* pStack);

//����ջ
void DestoryStack(Stack* pStack);

//ջ�Ĵ�С
SDataType StackSize(Stack* pStack);

//��ȡջ��Ԫ��
SDataType StackTop(Stack* pStack);

