#include<stdlib.h>
#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;

}*Stack;
bool InitStack(Stack &s);//��ʼ��ջ
void ClearStack(Stack &s);//���ջ
void DestroyStack(Stack &s);//����ջ
int StackEmpty(Stack s);//ջ�Ƿ�Ϊ��
int Push(Stack &s, ElemType e);//��ջ
int Pop(Stack &s, ElemType &e);//��ջ
int GetTop(Stack s, ElemType &e);//ȡջ��Ԫ��
void DispStack(Stack s);//��ʾջ��Ԫ��
int StackLength(Stack s);//ջ����
