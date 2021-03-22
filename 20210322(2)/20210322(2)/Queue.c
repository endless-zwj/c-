#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"


//��ʼ������
void InitQueue(Queue* pQ)
{
	pQ->_head = NULL;
	pQ->_tail = NULL;
}

//��ӡ����
void PrintQueue(Queue* pQ)
{
	assert(pQ);
	QueueNode* cur = pQ->_head ;
	printf("��ͷ[ ");
	while (cur != NULL)
	{
		printf("%d ",cur->_data);
		cur = cur->_next;
	}
	printf("]��β\n");
}

//�������ݽ�����
void PushQueue(Queue* pQ, QDataType x)
{
	assert(pQ);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode)* 1);
	if (newNode == NULL)
	{
		printf("�ڴ��ѿգ��޷�����\n");
		exit(-1);
	}

	//��ʼ���ڵ�
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
		//newNode = pQ->_tail;  �������ǽ� tail��ֵ���� newNode 
		//��û���𵽸ı�β������(tail����˭��ֵ��ָ��˭)
		pQ->_tail = newNode;
	}

}

//ɾ�����ݣ�������
void PopQueue(Queue* pQ)
{
	assert(pQ);
	assert(pQ->_head);//���pQ����Ԫ�أ��򱨴�

	QueueNode* head_next = pQ->_head->_next;//���ҵ�ͷ�ڵ����һ���ڵ�
	free(pQ->_head);//�ͷ�ͷ�ڵ�
	pQ->_head = head_next;//ת��ͷ�ڵ�
	if (head_next == NULL)
	{
		pQ->_tail = NULL ;//����������䣬˵��ֻ��һ���ڵ㣬ɾ����β��Ϊ��
	}

}

//��ͷ����
QDataType FrontQueue(Queue* pQ)
{
	assert(pQ);
	assert(pQ->_head);
	return pQ->_head->_data;
}

//��β����
QDataType BackQueue(Queue* pQ)
{
	assert(pQ);
	assert(pQ->_head);
	return pQ->_tail->_data;
}

//�����Ƿ�Ϊ�գ��Ƿ���1���񷵻�0
int EmptyQueue(Queue* pQ)
{
	assert(pQ);

	//�ô����Ϊ����
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

//���ٶ���
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
