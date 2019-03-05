#include<stdlib.h>
#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;

}*list;
bool InitList(list &L);//��ʼ��˳���
void DestroyList(list &L);//����˳���
void ClearList(list &L);//���˳���
int ListEmpty(list L);//�ж��Ƿ�Ϊ�ձ�
int ListLength(list L);//�󳤶�
void DispList(list L);//������Ա�
int GetElem(list L, int i, ElemType &e);//������Ԫ��ֵ
int LocateElem(list L, ElemType e);//����Ԫ��
char PriorElem(list L, ElemType e, ElemType pri_e);//���ǰ��
char NextElem(list L, ElemType e, ElemType next_e);//�������
int ListInsert(list &L, int i, ElemType e);//����Ԫ��
int ListDelect(list &L, int i, ElemType &e);//ɾ��Ԫ��
