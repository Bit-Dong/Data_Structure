#include<iostream>

#define maxsize 100

using namespace std;

//����˳��� 
typedef struct 
{
	int *elem;
	int length;
}list;

//����˳���
void cj(list &L)
{
	L.elem=new int[maxsize];
	L.length=0;
} 

//����˳��������
void sr(list &L,int &n)
{
	int i;
	cout<<"������"<<n<<"������"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>L.elem[i];
	}
	L.length=n;
 } 
 
 //��˳���ĳ���
 int cd(list &L)
 {
 	return L.length; 
  } 
  
//��˳���ĵ�i��Ԫ��,����e���� 
void cz(list &L,int i,int &e)
{
	e=L.elem[i-1];
 }
 
//�ж�list����û��e���Ԫ��
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
 
//��e ���뵽list�����
void  cdzh(list &L,int &e)
{
	L.elem[L.length]=e;
	L.length++;
}

//���list
void sc(list &L)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		cout<<L.elem[i]<<" ";
	}
	cout<<endl;
 } 
 
//���Ա�ĺϲ���˳���
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
	
	cout<<"���������Ա�A��Ԫ�ظ�����";
	cin>>n;
	sr(A,n);
	
	cout<<endl<<"���������Ա�B��Ԫ�ظ�����";
	cin>>m;
	sr(B,m);
	
	hb(A,B);
	cout<<"A��B�ϲ���ļ���Ϊ��"<<endl;
	sc(A);
	return 0;  
}
