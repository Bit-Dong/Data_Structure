#include<iostream>
 
#define ok 1
#define error 0

typedef int selemtype;
typedef int status;
using namespace std;

//链栈的定义
typedef struct node
{
    selemtype data;
	struct node *next;
 }node,* linklist;
 
//链栈的初始化
status csh(linklist &L)
{
	L=NULL;
	return ok;
 }
 
//链栈的入栈
status rz(linklist &L,selemtype &e)
{
	linklist p;
	p=new node;
	p->data=e;
	p->next=L;
	L=p;
	return ok;
 } 
 
//链栈的出栈
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
 
//取链栈的栈顶元素
status qzd(linklist &L,int e)
{
	if(L!=NULL)
	  e=L->data;
	return ok;
}

void zh(int m)     //对于任意一个非负十进制数，打印输出与其等值的八进制数 
{
	int e,i;
	linklist L;
	csh(L);     //初始化
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
	cout<<"输入一个非负十进制数："<<endl;
	cin>>n;
	
	zh(n);
	cout<<endl;
	return 0;
}

