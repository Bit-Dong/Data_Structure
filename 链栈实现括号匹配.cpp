#include<iostream>

#define ok 1
#define error 0

typedef int status;
typedef char selemtype;
using namespace std;

//���� 
typedef struct node
{
	selemtype data;
	struct node *next;
}node,*linklist;

//��ʼ�� 
status sch(linklist &L)
{
	L=NULL;
	return ok;
}

//��ջ
status rz(linklist &L,selemtype &e)
{
	linklist p;
	p=new node;
	p->data=e;
	p->next=L;
	L=p;
	return ok;
 } 
 
//��ջ
char cz(linklist &L,selemtype &e)
{
	if(L==NULL)
	  return error;
	linklist p;
	e=L->data;
	p=L;
	L=L->next;
	delete p;
	return e;
 } 
 
//ȡջ��Ԫ��
selemtype qzd(linklist &L)
{
	if(L!=NULL)
	  return L->data;
} 
 
//����ƥ�� 
status khpp(void)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
{
	linklist L;
	selemtype choose,e;
    cout<<"��������Ҫƥ������ŷ��ţ�"<<endl;
	status csh(linklist &L);
	cin>>choose;
	while(choose!='#')
	{
		switch(choose)
		{
			case '[':
				rz(L,choose);
				cout<<choose<<"Ϊ�����Ÿ�������ջ����"<<endl;
				break;
			case '(':
				rz(L,choose);
				cout<<choose<<"Ϊ�����Ÿ�������ջ����"<<endl;
				break;
			case ']':	
			    if(qzd(L)=='[')
			      cout<<cz(L,e)<<"��"<<choose<<"ƥ��ɹ���"<<endl;
			    else
			      cout<<cz(L,e)<<"��"<<choose<<"ƥ��ʧ�ܣ�"<<endl;
			      break;
			case ')':
				if(qzd(L)=='(') 
			      cout<<cz(L,e)<<"��"<<choose<<"ƥ��ɹ���"<<endl;
			    else
			      cout<<cz(L,e)<<"��"<<choose<<"ƥ��ʧ�ܣ�"<<endl;
			      break;
		}
		cin>>choose;
	}
}

int main()
{
	khpp();
	return 0;
}
