#pragma once

typedef int SLDataType; // 可以方便  进行更改  顺序表中 数据存放的类型
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>

//用结构体定义一个顺序表 ----> 一个结构体变量 就可 表示一个顺序表
typedef struct SeqList
{
	SLDataType* Array;
	int size;         // 该顺序表的有效长度
	int capacity;     // 顺序表的容量
}SeqList;

//声明该顺序表具有的 增删查改 的方法

//<1>尾插
void SeqListPushBack(SeqList* ps, SLDataType x); // ps 指向 需被修改的顺序表

//<2>尾删
void SeqListPopBack(SeqList* ps);

//<3>头插
void SeqListPushFront(SeqList* ps, SLDataType x);

//<4>头删
void SeqListPopFront(SeqList* ps);

//<5>随机插入
void SeqListInsert(SeqList* ps, int pos, SLDataType x);

//<6>随机删除
void SeqListErase(SeqList* ps, int pos);

//<7>查找
void SeqListFind(SeqList* ps, SLDataType x);

//<8>初始化顺序表
void SeqListInit(SeqList* ps);

//<9>检查顺序表是否扩容
void CheckSeqList(SeqList* ps);

//<10>打印顺序表
void PrintSeqList(SeqList* ps);