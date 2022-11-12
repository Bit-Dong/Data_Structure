#include<iostream>

#define OK 1
#define ERROR 0

typedef int Status;
using namespace std;

typedef struct StackNode {
	int data;
	struct StackNode *next;
} StackNode, *LinkStack;

//�㷨3.5����ջ�ĳ�ʼ��
Status InitStack(LinkStack &S) { // ����һ����ջ S��ջ��ָ���ÿ�
	S = NULL;
	return OK;
}
int StackEmpty(LinkStack &S)
{//��LΪ��ջ���򷵻�1�����򷵻�0 
   if(S)   //�ǿ� 
     return 0;
   else
     return 1;	
}
//�㷨3.6����ջ����ջ
Status Push(LinkStack &S, int e) {//��ջ������Ԫ��e
	LinkStack p;
	p = new StackNode; //�����½��
	p->data = e; //���½����������Ϊe
	p->next = S; //���½�����ջ��
	S = p; //�޸�ջ��ָ��Ϊp
	return OK;
}

//�㷨3.7����ջ�ĳ�ջ
Status Pop(LinkStack &S, int e) {//ɾ��S��ջ��Ԫ�أ���e������ֵ
	LinkStack p;
	if (S == NULL)
		return ERROR; //ջ��
	e = S->data; //��ջ��Ԫ�ظ���e
	p = S; //��p��ʱ����ջ��Ԫ�ؿռ䣬�Ա��ͷ�
	S = S->next; //�޸�ջ��ָ��
	delete p; //�ͷ�ԭջ��Ԫ�صĿռ�
	return OK;
}
void zh()     //��������һ���Ǹ�ʮ����������ӡ��������ֵ�İ˽����� 
{
	int e,m;
	LinkStack L;
	cout<<"������Ҫת����ʮ������ֵ��"<<endl;
	cin>>m;
	InitStack(L);     //��ʼ��
	while(m)
	{
	Push(L,m%8);
		m=m/8;
	}
	cout<<"ת��8���ƺ����ֵ�ǣ�"<<endl;
	while(Pop(L,e)) 
	{
		cout<<e;
	}
}

int main()
{
	zh();
	return 0;
}

