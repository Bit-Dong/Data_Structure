#include<iostream>

#define ok 1
#define error 0
#define overflow -1

typedef int status;
typedef char selemtype;
using namespace std;

//����Ķ��� 
typedef struct node
{
	selemtype data;
	struct node *next;
}node,* linklist;

//��巨���������㷨
status hcfcj(linklist &L,int n)
{
	L=new node;
	L->next=NULL;
	linklist p,r;
	int i;
	r=L;
	for(i=0;i<n;i++)
	{
	p=new node;
	cin>>p->data;
	p->next=NULL;
	r->next=p;
	r=p;
	}
	return ok;
 } 
 
//������������и������ĵݹ��㷨
status blsc(linklist &L)
{
	while(L)
	{
	if(L==NULL)
	  return error;
	else 
		cout<<L->data<<" ";
	L=L->next;
	}
	
	return ok;
}

int main()
{
	int n;
	linklist L;
	cout<<"������Ԫ�صĸ�����"<<endl;
	cin>>n;
	cout<<"����������Ԫ�أ�"<<endl;
	hcfcj(L,n);
	cout<<"�����е�Ԫ������Ϊ��"<<endl;
	blsc(L->next);
	cout<<endl;
	return 0;
 } 
