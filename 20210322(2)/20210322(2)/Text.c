#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

int main()
{
	Queue Q; //创建一个结构体Q 作为队列
	InitQueue(&Q);

	PushQueue(&Q, 10);
	PushQueue(&Q, 5);
	PushQueue(&Q, 10);
	PushQueue(&Q, 8);
	PrintQueue(&Q);


	printf("表头数据为:[%d]\n",FrontQueue(&Q));
	printf("表尾数据为:[%d]\n", BackQueue(&Q));

	
	PopQueue(&Q);
	PrintQueue(&Q); 

	PopQueue(&Q); 
	PopQueue(&Q);
	PrintQueue(&Q);
	PopQueue(&Q);
	PrintQueue(&Q);

	return 0;
}