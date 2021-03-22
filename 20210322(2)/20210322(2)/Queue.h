//队列的特点：先进先出(FIFO)
// 用数组实现时，在数据出队列时需挪动整个数组 不方便
// 相较而言，链表实现队列较为简便
// 以下是用单向链表的方式实现队列

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define QDataType int 

//队列组成元素为节点，故定义一个QueueNode的节点类型
typedef struct QueueNode
{
	QDataType _data ;
	struct QueueNode* _next ;
}QueueNode;

//因为一个队列有头有尾，我们需要用到首尾指针，
//因此我们可以封装一个含头尾指针的结构体来作为我们的队列
typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

//初始化队列
void InitQueue(Queue* pQ);

//打印队列
void PrintQueue(Queue* pQ);

//插入数据进队列
void PushQueue(Queue* pQ, QDataType x);

//删除数据
void PopQueue(Queue* pQ);

//队头数据
QDataType FrontQueue(Queue* pQ);

//队尾数据
QDataType BackQueue(Queue* pQ);

//队列是否为空，是返回1，否返回0
int EmptyQueue(Queue* pQ);

//销毁队列
void DestoryQueue(Queue* pQ);
