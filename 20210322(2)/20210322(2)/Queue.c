#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"


//初始化队列
void InitQueue(Queue* pQ)
{
	pQ->_head = NULL;
	pQ->_tail = NULL;
}

//打印队列
void PrintQueue(Queue* pQ)
{
	assert(pQ);
	QueueNode* cur = pQ->_head ;
	printf("队头[ ");
	while (cur != NULL)
	{
		printf("%d ",cur->_data);
		cur = cur->_next;
	}
	printf("]队尾\n");
}

//插入数据进队列
void PushQueue(Queue* pQ, QDataType x)
{
	assert(pQ);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode)* 1);
	if (newNode == NULL)
	{
		printf("内存已空，无法插入\n");
		exit(-1);
	}

	//初始化节点
	newNode->_data = x ;
	newNode->_next = NULL;

	if (pQ->_head == NULL)
	{
		pQ->_head = newNode ;
		pQ->_tail = newNode ;
	}
	else
	{
		pQ->_tail->_next = newNode ;
		//newNode = pQ->_tail;  这句代码是将 tail的值赋给 newNode 
		//并没有起到改变尾的作用(tail里存的谁的值便指向谁)
		pQ->_tail = newNode;
	}

}

//删除数据，出队列
void PopQueue(Queue* pQ)
{
	assert(pQ);
	assert(pQ->_head);//如果pQ里无元素，则报错

	QueueNode* head_next = pQ->_head->_next;//先找到头节点的下一个节点
	free(pQ->_head);//释放头节点
	pQ->_head = head_next;//转换头节点
	if (head_next == NULL)
	{
		pQ->_tail = NULL ;//进入这条语句，说明只有一个节点，删除后将尾置为空
	}

}

//队头数据
QDataType FrontQueue(Queue* pQ)
{
	assert(pQ);
	assert(pQ->_head);
	return pQ->_head->_data;
}

//队尾数据
QDataType BackQueue(Queue* pQ)
{
	assert(pQ);
	assert(pQ->_head);
	return pQ->_tail->_data;
}

//队列是否为空，是返回1，否返回0
int EmptyQueue(Queue* pQ)
{
	assert(pQ);

	//该代码较为冗余
	if (pQ->_head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}

	return pQ->_head == NULL ? 1 : 0;
}

//销毁队列
void DestoryQueue(Queue* pQ)
{
	assert(pQ);
	QueueNode* cur = pQ->_head ;
	while (cur != NULL)
	{
		QueueNode* cur_next = cur->_next;
		free(cur);
		cur = cur_next;
	}
	pQ->_head = NULL;
	pQ->_tail = NULL;
}
