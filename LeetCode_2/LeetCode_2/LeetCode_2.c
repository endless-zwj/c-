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

//初始化队列
void InitQueue(Queue* pQ)
{
	pQ->_head = NULL;
	pQ->_tail = NULL;
}
//插入数据进队列
void PushQueue(Queue * pQ, QDataType x)
{
	assert(pQ);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode)* 1);
	if (newNode == NULL)
	{
		printf("内存已空，无法插入\n");
		exit(-1);
	}

	//初始化节点
	newNode->_data = x;
	newNode->_next = NULL;//初始化节点，指针域置为空

	if (pQ->_head == NULL)
	{
		pQ->_head = newNode;
		pQ->_tail = newNode;
	}
	else
	{
		pQ->_tail->_next = newNode;
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

	QueueNode* head_next = pQ->_head->_next;//先找到头节点的下一个节点（以便释放头后仍能找到链表）
	free(pQ->_head);//释放头节点
	pQ->_head = head_next;//转换头节点
	if (head_next == NULL)
	{
		pQ->_tail = NULL;//进入这条语句，说明只有一个节点，删除后将尾置为空
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
	//动态开辟一块空间，这样出了这个函数，结构体也不会被当做局部变量销毁
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	//创建了一个栈后，初始化里面的队列
	InitQueue(&st->q1);
	InitQueue(&st->q2);

	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!EmptyQueue(&obj->q1))
	{
		PushQueue(&obj->q1, x); //如果 q1队列非空，则往q1内插入元素
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
	while (nonempty->_head->_next != NULL)//第二个节点不为空
	{
		PushQueue(empty, nonempty->_head->_data);//将nonempty队列里的头节点插入到empty队列当中
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

