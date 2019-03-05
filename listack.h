#include<stdlib.h>
#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;

}*Stack;
bool InitStack(Stack &s);//初始化栈
void ClearStack(Stack &s);//清空栈
void DestroyStack(Stack &s);//销毁栈
int StackEmpty(Stack s);//栈是否为空
int Push(Stack &s, ElemType e);//进栈
int Pop(Stack &s, ElemType &e);//出栈
int GetTop(Stack s, ElemType &e);//取栈顶元素
void DispStack(Stack s);//显示栈中元素
int StackLength(Stack s);//栈长度
