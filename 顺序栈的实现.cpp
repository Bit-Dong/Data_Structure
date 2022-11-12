#include<iostream> 

#define ok 1
#define error 0
#define maxsize 100
#define overflow -2

using namespace std;
typedef int status;
typedef char selemtype;

//顺序栈的定义
typedef struct
{
	selemtype *base;     //栈底指针 
	selemtype *top;      //栈顶指针 
	int stacksize;       //栈可用的最大容量 
 }sqstack;
 
//顺序栈的初始化
status csh(sqstack &S)
{
	S.base=new selemtype[maxsize];
	if(!S.base)
	  exit(overflow);
	S.top=S.base;
	S.stacksize=maxsize;
	return ok;
 } 
 
//顺序栈的入栈
status rz(sqstack &S,selemtype &e)
{
	if(S.top-S.base==S.stacksize)
	  return error;
	*S.top=e;
	S.top++;
	return ok;
 } 
 
//顺序栈的出栈
status cz(sqstack &S)
{
	if(S.top==S.base)
	  return error;
	S.top--;
	return ok;
 }
 
//取顺序栈的栈顶元素
selemtype qz(sqstack &S)
{
	if(S.top!=S.base)
	return *(S.top-1);
 } 
 
int main()
{
	sqstack S;
	int i,choose,n;
	selemtype e,a[maxsize];
	
	cout<<"1. 初始化"<<endl;
	cout<<"2. 入栈"<<endl;
	cout<<"3. 读栈顶元素"<<endl;
	cout<<"4. 出栈"<<endl;
	cout<<"0. 退出"<<endl;
	
	choose=-1;
	while(choose!=0)
	{
		cout<<"请选择：";
		cin>>choose;
		switch(choose)
		{
			case 1:
				if(csh(S))
				{
					cout<<"成功对栈进行初始化！"<<endl;
				}
				else
				  cout<<"初始化栈失败！"<<endl;
				break;
			case 2:
				cout<<"请输入需要入栈元素的个数n："<<endl;
				cin>>n;
				cout<<"输入需要入栈的元素："<<endl;
				for(i=0;i<n;i++)
				{
					cin>>a[i];
					rz(S,a[i]);
				}
				break;
			case 3:
				if(S.top!=S.base)
				  cout<<"栈顶元素为："<<qz(S)<<endl;
				else
				  cout<<"栈中无元素，请重新选择！"<<endl;
				break;
			case 4:
				cout<<"依次弹出栈的栈顶元素为："<<endl;
				while(cz(S))
				{
					cout<<*S.top;
				}
				cout<<endl;
				break;
		}
	}
	return 0;
}
