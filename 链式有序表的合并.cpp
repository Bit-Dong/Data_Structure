#include<iostream>

using namespace std;


//定义单链表 
typedef struct lnode
{
	int data;
	lnode *next;
}lnode,*linklist;

//创建单链表 
void cj(linklist &L)
{
	L=new lnode;
	L->next=NULL;
}

//输入数据
void sr(linklist &L,int n)
{
	int i;
	lnode *p,*r;
	r=L;
	cout<<"请输入该表的元素："<<endl;
	for(i=0;i<n;i++)
	{
		p=new lnode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
 } 
 
//输出元素
void sc(linklist &L)
{
	lnode *p;
	p=L->next;
	while(p)
	{
		cout<<p->data<<' ';
		p=p->next;
	}
 }
 
//链式有序表的合并
void hb(linklist &A,linklist &B,linklist &C)
{
	lnode *a,*b,*c;
	a=A->next;
	b=B->next;
	c=C;
	while(a&&b)
	{
		if(a->data<=b->data)
		{
			c->next=a;
		    c=a;
		    a=a->next;
		}
		else
		{
			c->next=b;
			c=b;
			b=b->next;
		}
	}
	c->next=a?a:b;
	delete B;
 } 
 
int main()
{
	linklist A,B,C;
	int a,b;
	
	cout<<"输入非递减单链表A的个数："<<endl;
	cin>>a;
	cj(A);
	sr(A,a);
	
	cout<<"输入非递减单链表B的个数："<<endl;
	cin>>b;
	cj(B);
	sr(B,b);
	
	cout<<"非递减单链表A,B合并后的单链表C为："<<endl;  
	cj(C);
	hb(A,B,C);
	sc(C);
	return 0;
}
