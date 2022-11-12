#include<iostream>
 
#define ok 1
#define error 0

typedef int selemtype;
typedef int status;
using namespace std;

//��ջ�Ķ���
typedef struct node
{
    selemtype data;
	struct node *next;
 }node,* linklist;
 
//��ջ�ĳ�ʼ��
status csh(linklist &L)
{
	L=NULL;
	return ok;
 }
 
//��ջ����ջ
status rz(linklist &L,selemtype &e)
{
	linklist p;
	p=new node;
	p->data=e;
	p->next=L;
	L=p;
	return ok;
 } 
 
//��ջ�ĳ�ջ
status cz(linklist &L,int &e)
{
	node *p;
	if(L==NULL)
	  return error;
	e=L->data;
	p=L;
	L=L->next;
	delete p;
	return ok;
 } 
 
//ȡ��ջ��ջ��Ԫ��
status qzd(linklist &L,int e)
{
	if(L!=NULL)
	  e=L->data;
	return ok;
}

void zh(int m)     //��������һ���Ǹ�ʮ����������ӡ��������ֵ�İ˽����� 
{
	int e,i;
	linklist L;
	csh(L);     //��ʼ��
	while(m)
	{
	    i=m%8;
		rz(L,i);
		m=m/8;
	}
	while(cz(L,e)) 
	{
		cout<<e;
	}
}

int main()
{
	int n;
	cout<<"����һ���Ǹ�ʮ��������"<<endl;
	cin>>n;
	
	zh(n);
	cout<<endl;
	return 0;
}

