#include"listack.h"
bool InitStack(Stack &s)//��ʼ��ջ
{
	s= (Node*)malloc(sizeof(Node));
	if (!s) return false;
    s->next = NULL;
	return true;
}
void ClearStack(Stack &s)//���ջ
{
	s->next = NULL;
}
void DestroyStack(Stack &s)//����ջ
{
	Stack p = s, q = s->next;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
	p = NULL;
}
int StackEmpty(Stack s)//ջ�Ƿ�Ϊ��
{
	return(s->next == NULL);
}
int Push(Stack &s, ElemType e)//��ջ
{
	Stack p;
	p = (Node*)malloc(sizeof(Node));
	if (!p) return 0;
	p->data = e;
	p->next = s->next;
	s->next = p;
	return 1;
}
int Pop(Stack &s, ElemType &e)//��ջ
{
	Stack p;
	if (s->next == NULL) return 0;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return 1;
}
int GetTop(Stack s, ElemType &e)//ȡջ��Ԫ��
{
	if (s->next == NULL) return 0;
	e = s->next->data;
	return 1;
}
void DispStack(Stack s)//��ʾջ��Ԫ��
{
	Stack p = s->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int StackLength(Stack s)//ջ����
{
	int n = 0;
	Stack p=s->next;
	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	return n;

}
