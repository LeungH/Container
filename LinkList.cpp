#include"LinkList.h"
bool InitList(list &L)//初始化顺序表
{
	L = (LNode *)malloc(sizeof(LNode));
	if (!L) return false;
	L->next = NULL;
	return true;
}
void DestroyList(list &L)//销毁顺序表
{
	list p = L,q = L->next;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
	p = NULL;
}
void ClearList(list &L)//清空顺序表
{
	L->next = NULL;
}
int ListEmpty(list L)//判断是否为空表
{
	return(L->next == NULL);
}
int ListLength(list L)//求长度
{
	list p=L;
	int i = 0;
	if(p == NULL) return 0;
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
			i++;
		}
		return i;
	}
}
void DispList(list L)//输出线性表
{
	list p = L->next;
	while (p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
int GetElem(list L, int i, ElemType &e)//求数据元素值
{
	int n=1;
	list p=L->next;
	while (n<i&&p!=NULL)
	{
		p = p->next;
		n++;
	}
	if (p == NULL) return 0;
	else
	{
		e = p->data;
		return 1;
	}
}
int LocateElem(list L, ElemType e)//查找元素
{
	int i=1;
	list p=L->next;
	while (p != NULL&&p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL) return 0; 
	else return i;
}
ElemType PriorElem(list L, ElemType e, ElemType pri_e)//输出前驱
{
	int i = 1;
	list p = L->next;
	while (p != NULL&&p->data != e)
	{
		pri_e = p->data;
		p = p->next;
	}
	if (p == NULL) pri_e = ' ';
	return pri_e;
}
ElemType NextElem(list L, ElemType e, ElemType next_e)//输出后驱
{
	list p = L->next;
	while (p != NULL&&p->data != e)
	{
		p = p->next;
	}
	if (p == NULL) next_e = ' ';
	else
	{
		p = p->next;
		next_e = p->data;
	}
	return next_e;

}
int ListInsert(list &L, int i, ElemType e)//插入元素
{
	int n=0;
	list p = L,s;
	while (n<i-1&&p!=NULL)
	{
		p = p->next;
		n++;
	}
	if (p == NULL||i<1) return 0;
	else
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return 1;
	}
}
int ListDelect(list &L, int i, ElemType &e)//删除元素
{
	int n=0;
	list p = L,q;
	while (n < i - 1 && p != NULL)
	{
		p = p->next;
		n++;
	}
	if (p == NULL||i<1) return 0;
	else
	{
		q = p->next;
		if (q == NULL) return 0;
		e = q->data;
		p->next = q->next;
		free(q);
		return 1;
	}
}
