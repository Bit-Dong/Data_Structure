#include<iostream>

#define ok 1
#define error 0
#define maxsize 100

typedef int status;
typedef char selemtype;
using namespace std;

//循环队列的定义
typedef struct sq
{
	selemtype *base;   //初始化时动态分配存储空间 
	int front;
	int rear;
 }sq;
 
//循环队列的初始化
status csh(sq &L)
{
	L.base=new selemtype[maxsize];
	if(!L.base)
	  return error;
	L.front=L.rear=0;
	return ok; 
 }
 
//求循环队列的长度
status cd(sq &L)
{
	return (L.rear-L.front+maxsize)%maxsize;
 }
 
//循环队列的入队
status rd(sq &L,selemtype &e)              //插入元素e为L的新的队尾元素 
{
	if((L.rear+1+maxsize)%maxsize==L.front)
	  return error;
	L.base[L.rear]=e;
	L.rear=(L.rear+1)%maxsize;
	return ok;
 } 
 
//循环队列的出队
status cd(sq &L,selemtype &e)            //删除L的队头元素，用e返回其值 
{
	if(L.front==L.rear)
	  return error;
	e=L.base[L.front];
	L.front=(L.front+1)%maxsize;
	return ok;
 } 
 
//取循环队列的队头元素 
selemtype qdt(sq &L)
{
	if(L.front!=L.rear)
	  return L.base[L.front];
}

int main()
{
	int choose,n,i;
	sq L;
	selemtype e,a;
	
	cout<<"1. 初始化"<<endl;
	cout<<"2. 入队"<<endl;
	cout<<"3. 读队头元素"<<endl;
	cout<<"4. 出队"<<endl;
	cout<<"0. 退出"<<endl;
	
	choose=1;
	while(choose!=0)
	{
		cout<<"请选择："<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				if(csh(L))
				  cout<<"循环队列初始化成功！"<<endl;
				else
				  cout<<"循环队列初始化失败！" <<endl;
				break;
			case 2:
				if((L.rear+1)%maxsize==L.front)
				  return error;
				cout<<"请输入想入队元素的个数："<<endl;
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

