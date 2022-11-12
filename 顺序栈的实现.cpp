#include<iostream> 

#define ok 1
#define error 0
#define maxsize 100
#define overflow -2

using namespace std;
typedef int status;
typedef char selemtype;

//˳��ջ�Ķ���
typedef struct
{
	selemtype *base;     //ջ��ָ�� 
	selemtype *top;      //ջ��ָ�� 
	int stacksize;       //ջ���õ�������� 
 }sqstack;
 
//˳��ջ�ĳ�ʼ��
status csh(sqstack &S)
{
	S.base=new selemtype[maxsize];
	if(!S.base)
	  exit(overflow);
	S.top=S.base;
	S.stacksize=maxsize;
	return ok;
 } 
 
//˳��ջ����ջ
status rz(sqstack &S,selemtype &e)
{
	if(S.top-S.base==S.stacksize)
	  return error;
	*S.top=e;
	S.top++;
	return ok;
 } 
 
//˳��ջ�ĳ�ջ
status cz(sqstack &S)
{
	if(S.top==S.base)
	  return error;
	S.top--;
	return ok;
 }
 
//ȡ˳��ջ��ջ��Ԫ��
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
	
	cout<<"1. ��ʼ��"<<endl;
	cout<<"2. ��ջ"<<endl;
	cout<<"3. ��ջ��Ԫ��"<<endl;
	cout<<"4. ��ջ"<<endl;
	cout<<"0. �˳�"<<endl;
	
	choose=-1;
	while(choose!=0)
	{
		cout<<"��ѡ��";
		cin>>choose;
		switch(choose)
		{
			case 1:
				if(csh(S))
				{
					cout<<"�ɹ���ջ���г�ʼ����"<<endl;
				}
				else
				  cout<<"��ʼ��ջʧ�ܣ�"<<endl;
				break;
			case 2:
				cout<<"��������Ҫ��ջԪ�صĸ���n��"<<endl;
				cin>>n;
				cout<<"������Ҫ��ջ��Ԫ�أ�"<<endl;
				for(i=0;i<n;i++)
				{
					cin>>a[i];
					rz(S,a[i]);
				}
				break;
			case 3:
				if(S.top!=S.base)
				  cout<<"ջ��Ԫ��Ϊ��"<<qz(S)<<endl;
				else
				  cout<<"ջ����Ԫ�أ�������ѡ��"<<endl;
				break;
			case 4:
				cout<<"���ε���ջ��ջ��Ԫ��Ϊ��"<<endl;
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
