#include<stdio.h>
#include<cstdio>
#include<math.h>
#include<stack>
using namespace std;
stack<double>opnd;//储存运算符
stack<char>optr;//储存运算符
char pre;//记录当前字符的前一个字符，用于辅助的判断
int flag;//值=1表示为赌注，否则为正数

void init()//初始化
{
    optr.push('#');
    pre = '#';
    flag = 0;
}

int IsNumber(char c)//检查是否为数字
{
    if(c >= '0'&&c<='9')
        return 1;
    return 0;
}

 int ErrorCheck(char c)//返回表示不是规定运算符
 {
     if(c=='+'||c=='-'||c=='*'||c=='/'||c==')'||c=='('||c=='#')
        return 0;
     return 1;
 }

 char Precede(char f,char l)//运算及判断
 {
     if(f=='+'||f=='-')
     {
         if(1=='*'||1=='/'||1=='(')
                return '<';
                else return '>';
     }
     if(f=='*'||f=='/')
     {
         if(1=='(')return '<';
         else return '>';
     }
     if(f=='(')
     {
         if(1==')')return '=';
         else if(1!='#')return '<';
     }
     if(f==')'&&1!='(')return '>';
     if(f=='#')
     {
         if(1=='#')return '=';
         else if(1!=')')return '<';
     }
     return '0';
 }

double Compute(double b,char oper,double a)
{
    if(oper=='-')return a-b;
    if(oper=='+')return a+b;
    if(oper=='*')return a*b;
    if(oper=='/')return a/b;
}

int main()
{
    init();
    char ch=getchar();
    while(ch!='#'||optr.top()!='#')
    {
        if(IsNumber(ch))
        {
            double tot=0;
            do
            {
                tot*=10;
                tot+=(ch-'0');
                pre=ch;
                ch=getchar();
            }
            while(IsNumber(ch));
            if(ch=='.')//小数点后的数值
            {
                ch=getchar();
                double tmp=0.1;
                while(IsNumber(ch))
                {
                    tot+=(ch-'0')*tmp;
                    tmp*=0.1;
                    pre=ch;
                    ch=getchar();
                }
            }
            if(flag)
            {
                tot=0-tot;
                flag=0;
            }
            opnd.push(tot);
        }
        else if(ch=='-'&&(pre=='#'||pre=='('))
        {
            flag=1;
            ch=getchar();
        }
        else
        {
            if(ErrorCheck(ch))
            {
                printf("存在非规定的运算字符！/n");
                return 0;
            }
            switch(Precede(optr.top(),ch))
            {
                case'<'://栈顶运算符优先级小
                {
                    optr.push(ch);
                    pre=ch;
                    ch=getchar();//重新接受下一个字符
                    break;
                }
                case'=':
                    {
                        optr.pop();//出栈一对括号
                        pre=ch;
                        ch=getchar();//重新接收下一个字符
                        break;
                    }
                case'>':
                    {
                      char oper=optr.top();
                      optr.pop();//出栈一个运算符
                      double a=opnd.top();opnd.pop();
                      double b=opnd.top();opnd.pop();//出栈两个操作数
                      double tot=Compute(a,oper,b);//计算值，并将结果压入堆栈
                      opnd.push(tot);
                      break;
                    }
                case'0':
                    {
                        printf("表达式语法错误，括号不匹配！\n");
                        return 0;
                        break;
                    }
            }//switch
        }//else
    }//while
    printf("%.21f\n",opnd.top());
    opnd.pop();
    return 0;
}

