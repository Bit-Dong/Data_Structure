#include<iostream>

#define ok 1
#define error 0
#define overflow -2

using namespace std;
typedef int elemtype;
typedef int status;

//������Ķ���
typedef struct lnode
{
	elemtype data;
	struct lnode *next;
}lnode,* linklist;       //linklistΪָ��ṹ��lnode��ָ������ 

//��ʼ��
status csh(linklist &L)
{
	L=new lnode;
	L->next=NULL;
	return ok;
} 

//��λ�ò���
status awzcz(linklist &L,int i,elemtype &e)   //�ڴ�ͷ���ĵ�����L�в��ҵ�i��Ԫ�� 
{
	int j;
	lnode *p;
	p=L->next;j=1;        //��ʼ����pָ���һ����㣬jΪ������ 
	while(p&&j<i) 
	{
		p=p->next;
		++j;
	}
	if(!p||j>i) return error;      //��i��Ԫ�ز����� 
	e=p->data;
	return ok;
}

//��ֵ����
lnode *azcz(linklist L,elemtype &e)
{
	lnode *p;
	p=L->next;
	while(p&&p->data!=e)
	{
		p=p->next;
	}
	return p;
} 

//����
status cr(linklist &L,int i,elemtype &e)
{
	int j;
	lnode *p,*s;
	p=L;j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)  return error;
	s=new lnode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return ok;
 } 
 
 //ɾ��
status sc(linklist &L,int i,elemtype &e)
{
	lnode *p,*q;
	int j;
	p=L;j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)  return error;
	q=p->next;
	p->next=q->next;
	e=q->data;
	delete q;
	return ok;
}

//ǰ�巨
status qcf(linklist &L,int n)
{
	lnode *p;
	L=new lnode;
	L->next=NULL;
	cout<<"������"<<n<<"����\n";
	for(int i=n;i>0;i--)
	{
		p=new lnode;
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
	return ok;
} 

//��巨
status hcf(linklist &L,int n)
{
	lnode *r,*p;
	L=new lnode;
	L->next=NULL;
	r=L;
	cout<<"������"<<n<<"����\n"; 
	for(int i=0;i<n;i++)
	{
		p=new lnode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
	return ok;
} 

int main()
{
	int j,res,a,b,n,choose;
	lnode *L,*p;
	cout<<"1. ��������\n";
	cout<<"2. ��������\n";
	cout<<"3. ��λ�ò���\n";
	cout<<"4. ��ֵ����\n";
	cout<<"5. ����Ĳ���:\n";
	cout<<"6. �����ɾ��:\n";
	cout<<"7. �������:\n";
	cout<<"0. �˳�:\n";
	
	choose=-1;
	while(choose!=0)
	{
		cout<<"��ѡ��:"<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				if(csh(L))
				  cout<<"�ɹ���������"<<endl;
				break;
			case 2:
				cout<<"�����봴�����������ݵĸ���n��";
				cin>>n;
				hcf(L,n);
				//qcf(L,n);
				cout<<"�ɹ�����������"<<endl;
				break;
			case 3:
				cout<<"����һ��λ����������";
				cin>>a; 
			    if(awzcz(L,a,res))
				  cout<<"���ҳɹ�����"<<a<<"������:"<<res<<endl;
				else
				  cout<<"����ʧ�ܣ�"<<endl;
				break;
			case 4:
			    cout<<"������һ����ֵ��������:";
				cin>>b;	
				if(azcz(L,b)!=NULL)
				  cout<<"���ҳɹ���"<<endl;
				else
				  cout<<"����ʧ�ܣ�"<<b<<"û���ҵ���";
				break;
			case 5:
				cout<<"�������������ֱ��������λ�ú�����:";
				cin>>a>>b;
				if(cr(L,a,b))
				  cout<<"�ɹ���"<<b<<"���ڵ�"<<a<<"��λ���ϣ�"<<endl;
				else
				  cout<<"����ʧ�ܣ�";
				break;
			case 6:
				cout<<"������һ��λ������ɾ��:";
				cin>>a;
				if(sc(L,a,res))
				  cout<<"ɾ���ɹ�����ɾ��������"<<res<<endl;
				else
				  cout<<"ɾ��ʧ�ܣ�"<<endl;
				break;
			case 7:
				cout<<"��������������ֱ��ǣ�"<<endl;
				p=L->next;
				while(p)
				{
					cout<<p->data<<" ";
					p=p->next;
				}
				cout<<endl;
				break;
		}
	}
	return 0;
}
