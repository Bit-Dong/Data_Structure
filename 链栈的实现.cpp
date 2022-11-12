#include<iostream>

#define ok 1
#define error 0
#define overflow -2

typedef int status;
typedef char selemtype;
using namespace std;

//��ջ�Ķ���
typedef struct node
{
	selemtype data;
	struct node *next;
 }node,* linklist;
 
//��ջ�ĳ�ʼ��
status csh(linklist &L)
{
	L=NULL;
	return ok;
 }
 
//��ջ����ջ
status rz(linklist &L,selemtype &e)
{
	linklist p;
	p=new node;
	p->data=e;
	p->next=L;
	L=p;
	return ok;
 } 
 
//��ջ�ĳ�ջ
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
 
//ȡ��ջ��ջ��Ԫ��
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
	
	cout<<"1. ��ʼ��"<<endl;
	cout<<"2. ��ջ"<<endl;
	cout<<"3. ��ջ��Ԫ��"<<endl;
	cout<<"4. ��ջ"<<endl;
	cout<<"0. �˳�"<<endl;
	
	choose=-1;
	while(choose)
	{
		cout<<"��ѡ��"<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				if(csh(L))
				cout<<"��ʼ���ɹ���";
				else
				cout<<"��ʼ��ʧ�ܣ�";
				break;
			case 2:
				cout<<"����������ջ��Ԫ�ظ���n��"<<endl;
				cin>>n;
				cout<<"����������ջ��Ԫ��"<<endl; 
				for(i=0;i<n;i++)
				{
					cin>>a[i];
					rz(L,a[i]);
				}
				break;
			case 3:
				qzd(L,j);
			    cout<<"���ջ��Ԫ��Ϊ��"<<endl<<j<<endl;
				break;
			case 4:
			    cout<<"���ε�����ջ��Ԫ��Ϊ: "<<endl;
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
 
