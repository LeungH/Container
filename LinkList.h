#include<stdlib.h>
#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;

}*list;
bool InitList(list &L);//初始化顺序表
void DestroyList(list &L);//销毁顺序表
void ClearList(list &L);//清空顺序表
int ListEmpty(list L);//判断是否为空表
int ListLength(list L);//求长度
void DispList(list L);//输出线性表
int GetElem(list L, int i, ElemType &e);//求数据元素值
int LocateElem(list L, ElemType e);//查找元素
char PriorElem(list L, ElemType e, ElemType pri_e);//输出前驱
char NextElem(list L, ElemType e, ElemType next_e);//输出后驱
int ListInsert(list &L, int i, ElemType e);//插入元素
int ListDelect(list &L, int i, ElemType &e);//删除元素
