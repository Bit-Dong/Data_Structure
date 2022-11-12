#include<iostream>

#define ok 1
#define error 0
#define maxsize 100

typedef int status;
typedef char selemtype;
using namespace std;

//ѭ�����еĶ���
typedef struct sq
{
	selemtype *base;   //��ʼ��ʱ��̬����洢�ռ� 
	int front;
	int rear;
 }sq;
 
//ѭ�����еĳ�ʼ��
status csh(sq &L)
{
	L.base=new selemtype[maxsize];
	if(!L.base)
	  return error;
	L.front=L.rear=0;
	return ok; 
 }
 
//��ѭ�����еĳ���
status cd(sq &L)
{
	return (L.rear-L.front+maxsize)%maxsize;
 }
 
//ѭ�����е����
status rd(sq &L,selemtype &e)              //����Ԫ��eΪL���µĶ�βԪ�� 
{
	if((L.rear+1+maxsize)%maxsize==L.front)
	  return error;
	L.base[L.rear]=e;
	L.rear=(L.rear+1)%maxsize;
	return ok;
 } 
 
//ѭ�����еĳ���
status cd(sq &L,selemtype &e)            //ɾ��L�Ķ�ͷԪ�أ���e������ֵ 
{
	if(L.front==L.rear)
	  return error;
	e=L.base[L.front];
	L.front=(L.front+1)%maxsize;
	return ok;
 } 
 
//ȡѭ�����еĶ�ͷԪ�� 
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
	
	cout<<"1. ��ʼ��"<<endl;
	cout<<"2. ���"<<endl;
	cout<<"3. ����ͷԪ��"<<endl;
	cout<<"4. ����"<<endl;
	cout<<"0. �˳�"<<endl;
	
	choose=1;
	while(choose!=0)
	{
		cout<<"��ѡ��"<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				if(csh(L))
				  cout<<"ѭ�����г�ʼ���ɹ���"<<endl;
				else
				  cout<<"ѭ�����г�ʼ��ʧ�ܣ�" <<endl;
				break;
			case 2:
				if((L.rear+1)%maxsize==L.front)
				  return error;
				cout<<"�����������Ԫ�صĸ�����"<<endl;
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

