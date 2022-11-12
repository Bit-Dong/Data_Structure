#include<iostream>

#define ok 1
#define error 0
#define overflow -2

using namespace std;
typedef int elemtype;
typedef int status;

//单链表的定义
typedef struct lnode
{
	elemtype data;
	struct lnode *next;
}lnode,* linklist;       //linklist为指向结构体lnode的指针类型 

//初始化
status csh(linklist &L)
{
	L=new lnode;
	L->next=NULL;
	return ok;
} 

//按位置查找
status awzcz(linklist &L,int i,elemtype &e)   //在带头结点的单链表L中查找第i个元素 
{
	int j;
	lnode *p;
	p=L->next;j=1;        //初始化，p指向第一个结点，j为计数器 
	while(p&&j<i) 
	{
		p=p->next;
		++j;
	}
	if(!p||j>i) return error;      //第i个元素不存在 
	e=p->data;
	return ok;
}

//按值查找
lnode *azcz(linklist L,elemtype &e)
{
	lnode *p;
	p=L->next;
	while(p&&p->data!=e)
	{
		p=p->next;
	}
	return p;
} 

//插入
status cr(linklist &L,int i,elemtype &e)
{
	int j;
	lnode *p,*s;
	p=L;j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)  return error;
	s=new lnode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return ok;
 } 
 
 //删除
status sc(linklist &L,int i,elemtype &e)
{
	lnode *p,*q;
	int j;
	p=L;j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)  return error;
	q=p->next;
	p->next=q->next;
	e=q->data;
	delete q;
	return ok;
}

//前插法
status qcf(linklist &L,int n)
{
	lnode *p;
	L=new lnode;
	L->next=NULL;
	cout<<"请输入"<<n<<"个数\n";
	for(int i=n;i>0;i--)
	{
		p=new lnode;
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
	return ok;
} 

//后插法
status hcf(linklist &L,int n)
{
	lnode *r,*p;
	L=new lnode;
	L->next=NULL;
	r=L;
	cout<<"请输入"<<n<<"个数\n"; 
	for(int i=0;i<n;i++)
	{
		p=new lnode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
	return ok;
} 

int main()
{
	int j,res,a,b,n,choose;
	lnode *L,*p;
	cout<<"1. 建立链表\n";
	cout<<"2. 输入数据\n";
	cout<<"3. 按位置查找\n";
	cout<<"4. 按值查找\n";
	cout<<"5. 链表的插入:\n";
	cout<<"6. 链表的删除:\n";
	cout<<"7. 输出数据:\n";
	cout<<"0. 退出:\n";
	
	choose=-1;
	while(choose!=0)
	{
		cout<<"请选择:"<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				if(csh(L))
				  cout<<"成功建立链表！"<<endl;
				break;
			case 2:
				cout<<"输入想创建单链表数据的个数n：";
				cin>>n;
				hcf(L,n);
				//qcf(L,n);
				cout<<"成功创建单链表！"<<endl;
				break;
			case 3:
				cout<<"输入一个位置用来查找";
				cin>>a; 
			    if(awzcz(L,a,res))
				  cout<<"查找成功！第"<<a<<"个数是:"<<res<<endl;
				else
				  cout<<"查找失败！"<<endl;
				break;
			case 4:
			    cout<<"请输入一个数值用来查找:";
				cin>>b;	
				if(azcz(L,b)!=NULL)
				  cout<<"查找成功！"<<endl;
				else
				  cout<<"查找失败！"<<b<<"没有找到！";
				break;
			case 5:
				cout<<"请输入两个数分别代表插入的位置和数据:";
				cin>>a>>b;
				if(cr(L,a,b))
				  cout<<"成功将"<<b<<"插在第"<<a<<"个位置上！"<<endl;
				else
				  cout<<"插入失败！";
				break;
			case 6:
				cout<<"请输入一个位置用来删除:";
				cin>>a;
				if(sc(L,a,res))
				  cout<<"删除成功！被删除的数是"<<res<<endl;
				else
				  cout<<"删除失败！"<<endl;
				break;
			case 7:
				cout<<"现在链表里的数分别是："<<endl;
				p=L->next;
				while(p)
				{
					cout<<p->data<<" ";
					p=p->next;
				}
				cout<<endl;
				break;
		}
	}
	return 0;
}
