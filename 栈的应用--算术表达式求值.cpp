#include<stdio.h>
#include<cstdio>
#include<math.h>
#include<stack>
using namespace std;
stack<double>opnd;//���������
stack<char>optr;//���������
char pre;//��¼��ǰ�ַ���ǰһ���ַ������ڸ������ж�
int flag;//ֵ=1��ʾΪ��ע������Ϊ����

void init()//��ʼ��
{
    optr.push('#');
    pre = '#';
    flag = 0;
}

int IsNumber(char c)//����Ƿ�Ϊ����
{
    if(c >= '0'&&c<='9')
        return 1;
    return 0;
}

 int ErrorCheck(char c)//���ر�ʾ���ǹ涨�����
 {
     if(c=='+'||c=='-'||c=='*'||c=='/'||c==')'||c=='('||c=='#')
        return 0;
     return 1;
 }

 char Precede(char f,char l)//���㼰�ж�
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
            if(ch=='.')//С��������ֵ
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
                printf("���ڷǹ涨�������ַ���/n");
                return 0;
            }
            switch(Precede(optr.top(),ch))
            {
                case'<'://ջ����������ȼ�С
                {
                    optr.push(ch);
                    pre=ch;
                    ch=getchar();//���½�����һ���ַ�
                    break;
                }
                case'=':
                    {
                        optr.pop();//��ջһ������
                        pre=ch;
                        ch=getchar();//���½�����һ���ַ�
                        break;
                    }
                case'>':
                    {
                      char oper=optr.top();
                      optr.pop();//��ջһ�������
                      double a=opnd.top();opnd.pop();
                      double b=opnd.top();opnd.pop();//��ջ����������
                      double tot=Compute(a,oper,b);//����ֵ���������ѹ���ջ
                      opnd.push(tot);
                      break;
                    }
                case'0':
                    {
                        printf("���ʽ�﷨�������Ų�ƥ�䣡\n");
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

