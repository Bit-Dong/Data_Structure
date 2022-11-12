#include<iostream>

#define ok 1
#define error 0
#define overflow -1

typedef int status;
typedef char selemtype;
using namespace std;

//链表的定义 
typedef struct node
{
	selemtype data;
	struct node *next;
}node,* linklist;

//后插法创建链表算法
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
 
//遍历输出链表中各个结点的递归算法
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
	cout<<"请输入元素的个数："<<endl;
	cin>>n;
	cout<<"请输入链表元素："<<endl;
	hcfcj(L,n);
	cout<<"链表中的元素依次为："<<endl;
	blsc(L->next);
	cout<<endl;
	return 0;
 } 
