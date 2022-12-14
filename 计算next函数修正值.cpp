#include<iostream>
#include<cstring>

#define maxsize 100
#define ok 1
#define error 0
#define overflow -2

typedef char sstring[maxsize+1];          //0号单元存放串的长度 
typedef int status;
using namespace std;

//生成一个其值等于chars的串T 
status sc(sstring T,const char *chars)       
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

//计算next函数修正值
void get_nextval(sstring T,int nextval[])        //求模式串T的next函数修正值并存入数组nextval
{
	int i=1,j=0;
	nextval[1]=0;
	while(i<T[0])
	{
		if(j==0||T[i]==T[j])
		{
			++i;
			++j;
			if(T[i]!=T[j])
			{
				nextval[i]=j;
			}
			else
			    nextval[i]=nextval[j];
		}
		else
		    j=nextval[j];
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
	get_nextval(T,p);
	cout<<"主串和子串在第"<<kmp(S,T,1,p)<<"个字符处首次匹配"<<endl;
	return 0;
}
