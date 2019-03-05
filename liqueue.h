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
bool InitQueue(Queue &q);//��ʼ������
void ClearQueue(Queue &q);//��ն���
void DestroyQueue(Queue &q);//���ٶ���
int QueueEmpty(Queue q);//�ж϶����Ƿ�Ϊ��
int enQueue(Queue &q, ElemType e);//�����
int deQueue(Queue &q, ElemType &e);//������
int QueueLength(Queue q);//���г���
ElemType GetHead(Queue q, ElemType &e);//ȡ��ͷԪ��
void DispQueue(Queue q);//�������