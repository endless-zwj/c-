#define _CRT_SECURE_NO_WARNINGS

#include"Stack.h"

int main()
{
	Stack stack;
	InitStack(&stack);
	PushStack(&stack, 10);
	PushStack(&stack, 14);
	PushStack(&stack, 16);
	int ret = StackTop(&stack);
	printf("栈顶数据为:[%d]\n",ret);
	PrintStack(&stack);
	PopStack(&stack);
	PrintStack(&stack);
	PopStack(&stack);
	PrintStack(&stack);
	printf("栈的大小为 %d \n",StackSize(&stack));
	return 0;
}