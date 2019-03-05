#include"listack.h"
bool InitStack(Stack &s)//初始化栈
{
	s= (Node*)malloc(sizeof(Node));
	if (!s) return false;
    s->next = NULL;
	return true;
}
void ClearStack(Stack &s)//清空栈
{
	s->next = NULL;
}
void DestroyStack(Stack &s)//销毁栈
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
int StackEmpty(Stack s)//栈是否为空
{
	return(s->next == NULL);
}
int Push(Stack &s, ElemType e)//进栈
{
	Stack p;
	p = (Node*)malloc(sizeof(Node));
	if (!p) return 0;
	p->data = e;
	p->next = s->next;
	s->next = p;
	return 1;
}
int Pop(Stack &s, ElemType &e)//出栈
{
	Stack p;
	if (s->next == NULL) return 0;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return 1;
}
int GetTop(Stack s, ElemType &e)//取栈顶元素
{
	if (s->next == NULL) return 0;
	e = s->next->data;
	return 1;
}
void DispStack(Stack s)//显示栈中元素
{
	Stack p = s->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int StackLength(Stack s)//栈长度
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
