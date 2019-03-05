#include"liqueue.h"
bool InitQueue(Queue &q)//��ʼ������
{
	q.front = q.rear = (QNode *)malloc(sizeof(QNode));
	if (!q.front) return false;
	q.front->next = NULL;
	return true;
}
void ClearQueue(Queue &q)//��ն���
{
	q.rear = q.front;
	q.front->next = NULL;
}
void DestroyQueue(Queue &q)//���ٶ���
{
	Node *p = q.front,*r=p->next;
	while (r != NULL)
	{
		free(p);
		p = r;
		r = p->next;
	}
	free(r);
}
int QueueEmpty(Queue q)//�ж϶����Ƿ�Ϊ��
{
	return(q.front == q.rear);
}
int enQueue(Queue &q, ElemType e)//�����
{
	Node *p = (QNode *)malloc(sizeof(QNode));
	if (!p) return 0;
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	return 1;
}
int deQueue(Queue &q, ElemType &e)//������
{
	if (q.front == q.rear)return 0;
	Node *p=q.front->next;
	q.front->next = p->next;
	e = p->data;
	if (q.rear == p)
		q.rear = q.front;
	free(p);
	return 1;
}
int QueueLength(Queue q)//���г���
{
	Node *p = q.front->next;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
ElemType GetHead(Queue q, ElemType &e)//ȡ��ͷԪ��
{
	if (q.front->next == NULL) return ' ';
	else e=q.front->next->data;
	return e;
}
void DispQueue(Queue q)//�������
{
	Node *p = q.front->next;
	while (p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}