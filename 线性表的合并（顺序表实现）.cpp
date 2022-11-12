#include<iostream>

#define maxsize 100

using namespace std;

//定义顺序表 
typedef struct 
{
	int *elem;
	int length;
}list;

//创建顺序表
void cj(list &L)
{
	L.elem=new int[maxsize];
	L.length=0;
} 

//输入顺序表的数据
void sr(list &L,int &n)
{
	int i;
	cout<<"请输入"<<n<<"个数："<<endl;
	for(i=0;i<n;i++)
	{
		cin>>L.elem[i];
	}
	L.length=n;
 } 
 
 //求顺序表的长度
 int cd(list &L)
 {
 	return L.length; 
  } 
  
//求顺序表的第i个元素,并以e返回 
void cz(list &L,int i,int &e)
{
	e=L.elem[i-1];
 }
 
//判断list里有没有e这个元素
bool pd(list &L,int &e)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(e==L.elem[i])
		  return true; 
		  else
		  return false;
	}
	
 } 
 
//将e 插入到list的最后
void  cdzh(list &L,int &e)
{
	L.elem[L.length]=e;
	L.length++;
}

//输出list
void sc(list &L)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		cout<<L.elem[i]<<" ";
	}
	cout<<endl;
 } 
 
//线性表的合并（顺序表）
void hb(list &A,list &B)
{
	int len_A,len_B,i,e;
	len_A=cd(A);
	len_B=cd(B);
	for(i=1;i<=len_B;i++)
	{
		cz(B,i,e);
		if(!pd(A,e))
		{
			cdzh(A,e);
		}
	}
 } 
 
int main()
{
	list A,B;
	int n,m;
	cj(A);cj(B);
	
	cout<<"请输入线性表A的元素个数：";
	cin>>n;
	sr(A,n);
	
	cout<<endl<<"请输入线性表B的元素个数：";
	cin>>m;
	sr(B,m);
	
	hb(A,B);
	cout<<"A和B合并后的集合为："<<endl;
	sc(A);
	return 0;  
}
