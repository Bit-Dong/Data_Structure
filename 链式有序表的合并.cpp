#include<iostream>

using namespace std;


//���嵥���� 
typedef struct lnode
{
	int data;
	lnode *next;
}lnode,*linklist;

//���������� 
void cj(linklist &L)
{
	L=new lnode;
	L->next=NULL;
}

//��������
void sr(linklist &L,int n)
{
	int i;
	lnode *p,*r;
	r=L;
	cout<<"������ñ��Ԫ�أ�"<<endl;
	for(i=0;i<n;i++)
	{
		p=new lnode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
 } 
 
//���Ԫ��
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
 
//��ʽ�����ĺϲ�
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
	
	cout<<"����ǵݼ�������A�ĸ�����"<<endl;
	cin>>a;
	cj(A);
	sr(A,a);
	
	cout<<"����ǵݼ�������B�ĸ�����"<<endl;
	cin>>b;
	cj(B);
	sr(B,b);
	
	cout<<"�ǵݼ�������A,B�ϲ���ĵ�����CΪ��"<<endl;  
	cj(C);
	hb(A,B,C);
	sc(C);
	return 0;
}
