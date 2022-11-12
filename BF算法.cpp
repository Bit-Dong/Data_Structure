#include<iostream>
#include<cstring>

#define maxsize 100
#define ok 1
#define error 0
#define overflow -2

typedef char sstring[maxsize+1];          //0号单元存放串的长度 
typedef int status;
using namespace std;

status sc(sstring T,const char *chars)       //生成一个其值等于chars的串T 
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

//BF算法 
int BF(sstring S,sstring T,int pos)      //返回模式T在主串S中第pos个字符之后第s一次出现的位置。若不存在，则返回0 
{                                         //其中，T非空，1<=pos<=strlength(S)
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
	cout<<"主串和子串在第"<<BF(S,T,1)<<"个字符处首次匹配"<<endl;
	return 0;
}
