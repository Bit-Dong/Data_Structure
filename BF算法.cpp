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

//BF�㷨 
int BF(sstring S,sstring T,int pos)      //����ģʽT������S�е�pos���ַ�֮���sһ�γ��ֵ�λ�á��������ڣ��򷵻�0 
{                                         //���У�T�ǿգ�1<=pos<=strlength(S)
    int i=pos;
	int j=1;
	while(i<=S[0]&&j<=T[0])
	{
		if(S[i]==T[j])
		{
			++i;
			++j;
		}
		else
		{
			i=i-j+2;
			j=1;
		}
	}
	if(j>T[0])
	  return i-T[0];
	else
	  return error;
	return 0; 
}

int main()
{
	sstring S;
	sc(S,"vdhsjhss");
	sstring T;
	sc(T,"sjh");
	cout<<"�������Ӵ��ڵ�"<<BF(S,T,1)<<"���ַ����״�ƥ��"<<endl;
	return 0;
}
