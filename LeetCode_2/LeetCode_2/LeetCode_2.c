#define QDataType int 

typedef struct QueueNode{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _tail;
	QueueNode* _head;
} Queue;

//��ʼ������
void InitQueue(Queue* pQ)
{
	pQ->_head = NULL;
	pQ->_tail = NULL;
}
//�������ݽ�����
void PushQueue(Queue * pQ, QDataType x)
{
	assert(pQ);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode)* 1);
	if (newNode == NULL)
	{
		printf("�ڴ��ѿգ��޷�����\n");
		exit(-1);
	}

	//��ʼ���ڵ�
	newNode->_data = x;
	newNode->_next = NULL;//��ʼ���ڵ㣬ָ������Ϊ��

	if (pQ->_head == NULL)
	{
		pQ->_head = newNode;
		pQ->_tail = newNode;
	}
	else
	{
		pQ->_tail->_next = newNode;
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

	QueueNode* head_next = pQ->_head->_next;//���ҵ�ͷ�ڵ����һ���ڵ㣨�Ա��ͷ�ͷ�������ҵ�����
	free(pQ->_head);//�ͷ�ͷ�ڵ�
	pQ->_head = head_next;//ת��ͷ�ڵ�
	if (head_next == NULL)
	{
		pQ->_tail = NULL;//����������䣬˵��ֻ��һ���ڵ㣬ɾ����β��Ϊ��
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
	QueueNode* cur = pQ->_head;
	while (cur != NULL)
	{
		QueueNode* cur_next = cur->_next;
		free(cur);
		cur = cur_next;
	}
	pQ->_head = NULL;
	pQ->_tail = NULL;
}

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	//��̬����һ��ռ䣬������������������ṹ��Ҳ���ᱻ�����ֲ���������
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	//������һ��ջ�󣬳�ʼ������Ķ���
	InitQueue(&st->q1);
	InitQueue(&st->q2);

	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!EmptyQueue(&obj->q1))
	{
		PushQueue(&obj->q1, x); //��� q1���зǿգ�����q1�ڲ���Ԫ��
	}
	else
	{
		PushQueue(&obj->q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* empty = &obj->q1;
	Queue* nonempty = &obj->q2;
	if (!EmptyQueue(empty))
	{
		empty = &obj->q2;
		nonempty = &obj->q1;
	}
	while (nonempty->_head->_next != NULL)//�ڶ����ڵ㲻Ϊ��
	{
		PushQueue(empty, nonempty->_head->_data);//��nonempty�������ͷ�ڵ���뵽empty���е���
		PopQueue(nonempty);
	}
	int top = nonempty->_head->_data;
	PopQueue(nonempty);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (EmptyQueue(&obj->q1))
	{
		return BackQueue(&obj->q2);
	}
	else
	{
		return BackQueue(&obj->q1);

	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return EmptyQueue(&obj->q1) && EmptyQueue(&obj->q2);
}

void myStackFree(MyStack* obj) {
	DestoryQueue(&obj->q1);
	DestoryQueue(&obj->q2);
	free(obj);
}#define _CRT_SECURE_NO_WARNINGS

