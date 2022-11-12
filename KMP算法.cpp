#include<iostream>
#include<cstring>

#define maxsize 100
#define ok 1
#define error 0
#define overflow -2

typedef char sstring[maxsize+1];          //0�ŵ�Ԫ��Ŵ��ĳ��� 
typedef int status;
using namespace std;

status sc(sstring T,const char *chars)       //����һ����ֵ����chars�Ĵ�T 
{
	int i;
	if(strlen(chars)>maxsize)
	  return error;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
		  T[i]=*(chars+i-1);
		return ok;
	}
}

//����next����ֵ
void get_next(sstring T,int next[])        //��ģʽ��T��next����ֵ����������next 
{
	int i=1,j=0;
	next[1]=0;
	while(i<T[0])
	{
		if(j==0||T[i]==T[j])
		{
			++i;
			++j;
			next[i]=j;
		}
		else
		  j=next[j];
	}
 }

//KMP�㷨
int kmp(sstring S,sstring T,int pos,int next[])        //����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�kmp�㷨 
{                                                      //���У�T�ǿգ�1<= pos<=strlength(S)
	int i=pos,j=1;
	while(i<=S[0]&&j<=T[0])
	{
	    if(j==0||S[i]==T[j])
		{
		    ++i;
			++j;	
		}	
		else
		  j=next[j];
	}
	if(j>T[0])
	  return i-T[0];
	else
	  return error;
}

int main()
{
	sstring S;
	sc(S,"vdhsjhss");
	sstring T;
	sc(T,"sjh");
	int *p=new int[T[0]+1];
	get_next(T,p);
	cout<<"�������Ӵ��ڵ�"<<kmp(S,T,1,p)<<"���ַ����״�ƥ��"<<endl;
	return 0;
}
