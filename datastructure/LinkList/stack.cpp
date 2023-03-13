//ջ��˳��洢�ṹ
//ջ�Ľṹ����
#include <iostream>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
	ElemType date[MAXSIZE];
	int top;
}SqStack;

//��ջ����push
bool push(SqStack& s, ElemType e)
{
	if (s.top == MAXSIZE - 1)
		return false;
	s.top++;
	s.date[s.top] = e;
	return true;
}
//��ջ����pop
bool pop(SqStack& s, ElemType* e)
{
	if (s.top == -1)
		return false;
	*e = s.date[s.top];
	s.top--;
	return true;
}

//ջ����ʽ�洢�ṹ
typedef struct StackNode
{
	ElemType date;
	struct StackNode* next;
}StackNode,*LinkStackPtr;
typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;
//��ջ
bool Push(LinkStack* S, ElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->date = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return true;
}
//��ջ
bool Pop(LinkStack* S, ElemType* e)
{
	*e = S->top->date;
	LinkStackPtr p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return true;
}
