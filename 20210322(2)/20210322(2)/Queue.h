//���е��ص㣺�Ƚ��ȳ�(FIFO)
// ������ʵ��ʱ�������ݳ�����ʱ��Ų���������� ������
// ��϶��ԣ�����ʵ�ֶ��н�Ϊ���
// �������õ�������ķ�ʽʵ�ֶ���

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define QDataType int 

//�������Ԫ��Ϊ�ڵ㣬�ʶ���һ��QueueNode�Ľڵ�����
typedef struct QueueNode
{
	QDataType _data ;
	struct QueueNode* _next ;
}QueueNode;

//��Ϊһ��������ͷ��β��������Ҫ�õ���βָ�룬
//������ǿ��Է�װһ����ͷβָ��Ľṹ������Ϊ���ǵĶ���
typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

//��ʼ������
void InitQueue(Queue* pQ);

//��ӡ����
void PrintQueue(Queue* pQ);

//�������ݽ�����
void PushQueue(Queue* pQ, QDataType x);

//ɾ������
void PopQueue(Queue* pQ);

//��ͷ����
QDataType FrontQueue(Queue* pQ);

//��β����
QDataType BackQueue(Queue* pQ);

//�����Ƿ�Ϊ�գ��Ƿ���1���񷵻�0
int EmptyQueue(Queue* pQ);

//���ٶ���
void DestoryQueue(Queue* pQ);
