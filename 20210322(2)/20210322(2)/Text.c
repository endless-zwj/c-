#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

int main()
{
	Queue Q; //����һ���ṹ��Q ��Ϊ����
	InitQueue(&Q);

	PushQueue(&Q, 10);
	PushQueue(&Q, 5);
	PushQueue(&Q, 10);
	PushQueue(&Q, 8);
	PrintQueue(&Q);


	printf("��ͷ����Ϊ:[%d]\n",FrontQueue(&Q));
	printf("��β����Ϊ:[%d]\n", BackQueue(&Q));

	
	PopQueue(&Q);
	PrintQueue(&Q); 

	PopQueue(&Q); 
	PopQueue(&Q);
	PrintQueue(&Q);
	PopQueue(&Q);
	PrintQueue(&Q);

	return 0;
}