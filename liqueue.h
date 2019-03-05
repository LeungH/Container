#include<iostream>
#include<stdlib.h>
using namespace std;
typedef char ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;

}QNode,*Queueptr;
typedef struct
{
	Queueptr front;
	Queueptr rear;
}Queue;
bool InitQueue(Queue &q);//初始化队列
void ClearQueue(Queue &q);//清空队列
void DestroyQueue(Queue &q);//销毁队列
int QueueEmpty(Queue q);//判断队列是否为空
int enQueue(Queue &q, ElemType e);//入队列
int deQueue(Queue &q, ElemType &e);//出队列
int QueueLength(Queue q);//队列长度
ElemType GetHead(Queue q, ElemType &e);//取队头元素
void DispQueue(Queue q);//输出队列