#include<iostream>

#define ok 1
#define error 0

typedef int status;
typedef char selemtype;
using namespace std;

//-------------队列的链式存储结构--------------
typedef struct qnode
{
	selemtype data;
	struct qnode *next;
 }qnode,* queue;
typedef struct
{
	queue front;        //队头指针 
	queue rear;         //队尾指针 
}link;

//链队的初始化
status csh(link &L)
{
	L.front=L.rear=new qnode;        //生成新结点作为头结点，队头和队尾指针指向此结点 
	L.front->next=NULL;                  //头结点的指针域置零 
	return ok;
 }
 
//链队的入队
status rd(link &L,selemtype &e)            //插入元素e为L的新队尾元素 
{
	queue p;
	p=new qnode;
	p->data=e;
	p->next=NULL;
	L.rear->next=p;
	L.rear=p;
	return ok;
 }
 
//链队的出队
status cd(link &L,selemtype &e)           //删除L的队头元素，用e返回其值 
{
	queue p;
	if(L.front==L.rear)
	  return error;
	p=L.front->next;
	e=p->data;
	L.front->next=p->next;
	if(L.rear==p)
	  L.rear=L.front;
	delete p;
	return ok;
 }
 
//取链队的队头元素
selemtype qdt(link &L)
{
	if(L.front!=L.rear)               //队列非空 
	  return L.front->next->data;
}

int main()
{
	int choose,i,n;
	link L;
	selemtype e,a;
	
	cout<<"1. 初始化"<<endl;
	cout<<"2. 入队"<<endl;
	cout<<"3. 读队头元素"<<endl;
	cout<<"4. 出队"<<endl;
	cout<<"0. 退出"<<endl;
	
	choose=1;
	while(choose)
	{
		cout<<"请选择："<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				if(csh(L))
				  cout<<"链式队列初始化成功！"<<endl;
				else
				  cout<<"链式队列初始化失败！" <<endl;
				break;
			case 2:
				cout<<"请输入想入队的元素个数："<<endl;
				cin>>n;
				cout<<"请输入想入队的元素："<<endl;
				for(i=0;i<n;i++)
				{
					cin>>e;
					rd(L,e);
				}
				cout<<"入队成功！"<<endl;
				break;
			case 3:
			    if(qdt(L))
				  cout<<"队头元素为："<<qdt(L)<<endl;
				else
				  cout<<"队列中无元素，请重新选择！"<<endl;
				break;
			case 4:
				cout<<"依次弹出的队头元素为："<<endl;
				while(cd(L,a))
				{
					cout<<a<<" ";
				}
				cout<<endl;
				break;
		}
	}
	return 0;
}

