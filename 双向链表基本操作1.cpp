#include<iostream>

#define ok 1
#define error 0
#define overflow -2

using namespace std;
typedef int elemtype;
typedef int status;

//˫������Ķ���
typedef struct tnode
{
	elemtype data;
	struct tnode *prior;
	struct tnode *next;
} tnode,* tlinklist;

//��ʼ��
status csh(tlinklist &L)
{
	L=new tnode;
	L->next=NULL;
	L->prior=NULL;
	return ok;
} 

//��λ�ò���
status awzcz(tlinklist &L,int i,elemtype &e)   //�ڴ�ͷ���ĵ�����L�в��ҵ�i��Ԫ�� 
{
	int j;
	tnode *p;
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

//����
status cr(tlinklist &L,int i,elemtype &e)
{
	tnode *s,*p;
	p=L->next;
	int j=0;
    while(j<i-1&&p)
    {
    	p=p->next;
    	++j;
	}
	if(j>i-1||!p)  return error;
	s=new tnode;
	s->next=NULL; 
	s->data=e;
	s->prior=p->prior;
	s->next=p;
	p->prior->next=s;
	/*s->prior->next=s; 
	s->next=p;
	p->prior=s;*/
	p->prior=s;
	return ok; 
} 

//ɾ��
status sc(tlinklist &L,elemtype &e)
{
	tnode *p;
	p=L;
	while(p->data!=e&&p->next)
	{
		p=p->next;
	}
	if(p->data==e)
	{
		e=p->data;
	    p->prior->next=p->next;
	    p->next->prior=p->prior;
	}
	else
	cout<<"δ��ѯ��������";
	return ok;
}
//��巨
status hcf(tlinklist &L,int n)
{
	tnode *r,*p;
	L=new tnode;
	L->next=NULL;
	r=L;
	cout<<"������"<<n<<"����"<<endl;
	for(int i=0;i<n;i++)
	{
		p=new tnode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
		p->prior=L->prior;
		L->prior=p;
	}
} 

int main()
{
	int res,a,b,n,choose;
	tnode *L,*p,*q;
	cout<<"1. ����˫������\n";
	cout<<"2. ��������\n";
	cout<<"3. ˫������Ĳ���\n";
	cout<<"4. ˫�������ɾ��\n";
	cout<<"5. �������:\n";
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
				  cout<<"�ɹ�����˫������"<<endl;
				break;
			case 2:
				cout<<"�����봴��˫���������ݵĸ���n��";
				cin>>n;
				hcf(L,n);
				cout<<"�ɹ�����˫������"<<endl;
				break;
			case 3:
				cout<<"�������������ֱ��������λ�ú���ֵ��";
				cin>>a>>b; 
			    if(cr(L,a,b))
				  cout<<"�ɹ��ڵ�"<<a<<"��λ�ò���"<<b<<endl;
				else
				  cout<<"����ʧ�ܣ�"<<endl;
				break;
            case 4:
            	cout<<"��������ɾ��������";
            	cin>>res;
            	if(sc(L,res))
            	  cout<<"ɾ���ɹ�����ɾ��������"<<res<<endl;
            	else
            	  cout<<"ɾ��ʧ�ܣ�";
            	break;
            case 5:
            	cout<<"���ڵ�˫�������ǣ�"<<endl;
            	q=L->next;
            	while(q)
            	{
            		cout<<q->data<<" ";
            		q=q->next;
				}
				cout<<endl;
				break;
		}
	}
	return 0;
}
