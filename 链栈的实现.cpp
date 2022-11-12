#include<iostream>

#define ok 1
#define error 0
#define overflow -2

typedef int status;
typedef char selemtype;
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
status cz(linklist &L,selemtype &e)
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
status qzd(linklist &L,selemtype &e)
{
	if(L!=NULL)
	  e=L->data;
	return ok;
 } 
 
int main()
{
	linklist L;
	int choose,i,n;
	selemtype e,j,a[100];
	
	cout<<"1. 初始化"<<endl;
	cout<<"2. 入栈"<<endl;
	cout<<"3. 读栈顶元素"<<endl;
	cout<<"4. 出栈"<<endl;
	cout<<"0. 退出"<<endl;
	
	choose=-1;
	while(choose)
	{
		cout<<"请选择："<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				if(csh(L))
				cout<<"初始化成功！";
				else
				cout<<"初始化失败！";
				break;
			case 2:
				cout<<"请输入想入栈的元素个数n："<<endl;
				cin>>n;
				cout<<"请输入想入栈的元素"<<endl; 
				for(i=0;i<n;i++)
				{
					cin>>a[i];
					rz(L,a[i]);
				}
				break;
			case 3:
				qzd(L,j);
			    cout<<"输出栈顶元素为："<<endl<<j<<endl;
				break;
			case 4:
			    cout<<"依次弹出的栈顶元素为: "<<endl;
				while(cz(L,e))
				{
					cout<<e<<" ";
				 } 
				cout<<endl;
				break;
		}
	}
	return 0; 
}
 
