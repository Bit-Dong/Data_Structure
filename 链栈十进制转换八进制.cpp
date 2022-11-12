#include<iostream>

#define OK 1
#define ERROR 0

typedef int Status;
using namespace std;

typedef struct StackNode {
	int data;
	struct StackNode *next;
} StackNode, *LinkStack;

//算法3.5　链栈的初始化
Status InitStack(LinkStack &S) { // 构造一个空栈 S，栈顶指针置空
	S = NULL;
	return OK;
}
int StackEmpty(LinkStack &S)
{//若L为空栈，则返回1，否则返回0 
   if(S)   //非空 
     return 0;
   else
     return 1;	
}
//算法3.6　链栈的入栈
Status Push(LinkStack &S, int e) {//在栈顶插入元素e
	LinkStack p;
	p = new StackNode; //生成新结点
	p->data = e; //将新结点数据域置为e
	p->next = S; //将新结点插入栈顶
	S = p; //修改栈顶指针为p
	return OK;
}

//算法3.7　链栈的出栈
Status Pop(LinkStack &S, int e) {//删除S的栈顶元素，用e返回其值
	LinkStack p;
	if (S == NULL)
		return ERROR; //栈空
	e = S->data; //将栈顶元素赋给e
	p = S; //用p临时保存栈顶元素空间，以备释放
	S = S->next; //修改栈顶指针
	delete p; //释放原栈顶元素的空间
	return OK;
}
void zh()     //对于任意一个非负十进制数，打印输出与其等值的八进制数 
{
	int e,m;
	LinkStack L;
	cout<<"输入需要转换的十进制数值："<<endl;
	cin>>m;
	InitStack(L);     //初始化
	while(m)
	{
	Push(L,m%8);
		m=m/8;
	}
	cout<<"转换8进制后的数值是："<<endl;
	while(Pop(L,e)) 
	{
		cout<<e;
	}
}

int main()
{
	zh();
	return 0;
}

