#include<iostream>

#define ok 1
#define error 0

typedef int status;
typedef char selemtype;
using namespace std;

//-------------���е���ʽ�洢�ṹ--------------
typedef struct qnode
{
	selemtype data;
	struct qnode *next;
 }qnode,* queue;
typedef struct
{
	queue front;        //��ͷָ�� 
	queue rear;         //��βָ�� 
}link;

//���ӵĳ�ʼ��
status csh(link &L)
{
	L.front=L.rear=new qnode;        //�����½����Ϊͷ��㣬��ͷ�Ͷ�βָ��ָ��˽�� 
	L.front->next=NULL;                  //ͷ����ָ�������� 
	return ok;
 }
 
//���ӵ����
status rd(link &L,selemtype &e)            //����Ԫ��eΪL���¶�βԪ�� 
{
	queue p;
	p=new qnode;
	p->data=e;
	p->next=NULL;
	L.rear->next=p;
	L.rear=p;
	return ok;
 }
 
//���ӵĳ���
status cd(link &L,selemtype &e)           //ɾ��L�Ķ�ͷԪ�أ���e������ֵ 
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
 
//ȡ���ӵĶ�ͷԪ��
selemtype qdt(link &L)
{
	if(L.front!=L.rear)               //���зǿ� 
	  return L.front->next->data;
}

int main()
{
	int choose,i,n;
	link L;
	selemtype e,a;
	
	cout<<"1. ��ʼ��"<<endl;
	cout<<"2. ���"<<endl;
	cout<<"3. ����ͷԪ��"<<endl;
	cout<<"4. ����"<<endl;
	cout<<"0. �˳�"<<endl;
	
	choose=1;
	while(choose)
	{
		cout<<"��ѡ��"<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				if(csh(L))
				  cout<<"��ʽ���г�ʼ���ɹ���"<<endl;
				else
				  cout<<"��ʽ���г�ʼ��ʧ�ܣ�" <<endl;
				break;
			case 2:
				cout<<"����������ӵ�Ԫ�ظ�����"<<endl;
				cin>>n;
				cout<<"����������ӵ�Ԫ�أ�"<<endl;
				for(i=0;i<n;i++)
				{
					cin>>e;
					rd(L,e);
				}
				cout<<"��ӳɹ���"<<endl;
				break;
			case 3:
			    if(qdt(L))
				  cout<<"��ͷԪ��Ϊ��"<<qdt(L)<<endl;
				else
				  cout<<"��������Ԫ�أ�������ѡ��"<<endl;
				break;
			case 4:
				cout<<"���ε����Ķ�ͷԪ��Ϊ��"<<endl;
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

