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

//计算next函数值
void get_next(sstring T,int next[])        //求模式串T的next函数值并存入数组next 
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

//KMP算法
int kmp(sstring S,sstring T,int pos,int next[])        //利用模式串T的next函数求T在主串S中第pos个字符之后的位置的kmp算法 
{                                                      //其中，T非空，1<= pos<=strlength(S)
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
	cout<<"主串和子串在第"<<kmp(S,T,1,p)<<"个字符处首次匹配"<<endl;
	return 0;
}
