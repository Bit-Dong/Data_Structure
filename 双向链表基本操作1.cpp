#include<iostream>

#define ok 1
#define error 0
#define overflow -2

using namespace std;
typedef int elemtype;
typedef int status;

//双向链表的定义
typedef struct tnode
{
	elemtype data;
	struct tnode *prior;
	struct tnode *next;
} tnode,* tlinklist;

//初始化
status csh(tlinklist &L)
{
	L=new tnode;
	L->next=NULL;
	L->prior=NULL;
	return ok;
} 

//按位置查找
status awzcz(tlinklist &L,int i,elemtype &e)   //在带头结点的单链表L中查找第i个元素 
{
	int j;
	tnode *p;
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

//插入
status cr(tlinklist &L,int i,elemtype &e)
{
	tnode *s,*p;
	p=L->next;
	int j=0;
    while(j<i-1&&p)
    {
    	p=p->next;
    	++j;
	}
	if(j>i-1||!p)  return error;
	s=new tnode;
	s->next=NULL; 
	s->data=e;
	s->prior=p->prior;
	s->next=p;
	p->prior->next=s;
	/*s->prior->next=s; 
	s->next=p;
	p->prior=s;*/
	p->prior=s;
	return ok; 
} 

//删除
status sc(tlinklist &L,elemtype &e)
{
	tnode *p;
	p=L;
	while(p->data!=e&&p->next)
	{
		p=p->next;
	}
	if(p->data==e)
	{
		e=p->data;
	    p->prior->next=p->next;
	    p->next->prior=p->prior;
	}
	else
	cout<<"未查询到该数！";
	return ok;
}
//后插法
status hcf(tlinklist &L,int n)
{
	tnode *r,*p;
	L=new tnode;
	L->next=NULL;
	r=L;
	cout<<"请输入"<<n<<"个数"<<endl;
	for(int i=0;i<n;i++)
	{
		p=new tnode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
		p->prior=L->prior;
		L->prior=p;
	}
} 

int main()
{
	int res,a,b,n,choose;
	tnode *L,*p,*q;
	cout<<"1. 建立双向链表\n";
	cout<<"2. 输入数据\n";
	cout<<"3. 双向链表的插入\n";
	cout<<"4. 双向链表的删除\n";
	cout<<"5. 输出数据:\n";
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
				  cout<<"成功建立双向链表！"<<endl;
				break;
			case 2:
				cout<<"输入想创建双向链表数据的个数n：";
				cin>>n;
				hcf(L,n);
				cout<<"成功建立双向链表！"<<endl;
				break;
			case 3:
				cout<<"请输入两个数分别代表插入的位置和数值：";
				cin>>a>>b; 
			    if(cr(L,a,b))
				  cout<<"成功在第"<<a<<"个位置插入"<<b<<endl;
				else
				  cout<<"插入失败！"<<endl;
				break;
            case 4:
            	cout<<"请输入想删除的数：";
            	cin>>res;
            	if(sc(L,res))
            	  cout<<"删除成功！被删除的数是"<<res<<endl;
            	else
            	  cout<<"删除失败！";
            	break;
            case 5:
            	cout<<"现在的双向链表是："<<endl;
            	q=L->next;
            	while(q)
            	{
            		cout<<q->data<<" ";
            		q=q->next;
				}
				cout<<endl;
				break;
		}
	}
	return 0;
}
