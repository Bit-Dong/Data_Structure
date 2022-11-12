#include<iostream>

#define ok 1
#define error 0

typedef int status;
typedef char selemtype;
using namespace std;

//∂®“Â 
typedef struct node
{
	selemtype data;
	struct node *next;
}node,*linklist;

//≥ı ºªØ 
status sch(linklist &L)
{
	L=NULL;
	return ok;
}

//»Î’ª
status rz(linklist &L,selemtype &e)
{
	linklist p;
	p=new node;
	p->data=e;
	p->next=L;
	L=p;
	return ok;
 } 
 
//≥ˆ’ª
char cz(linklist &L,selemtype &e)
{
	if(L==NULL)
	  return error;
	linklist p;
	e=L->data;
	p=L;
	L=L->next;
	delete p;
	return e;
 } 
 
//»°’ª∂•‘™Àÿ
selemtype qzd(linklist &L)
{
	if(L!=NULL)
	  return L->data;
} 
 
//¿®∫≈∆•≈‰ 
status khpp(void)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
{
	linklist L;
	selemtype choose,e;
    cout<<"«Î ‰»Î–Ë“™∆•≈‰µƒ¿®∫≈∑˚∫≈£∫"<<endl;
	status csh(linklist &L);
	cin>>choose;
	while(choose!='#')
	{
		switch(choose)
		{
			case '[':
				rz(L,choose);
				cout<<choose<<"Œ™◊Û¿®∫≈∏Æ£¨¥Ê»Î’ª∂•°£"<<endl;
				break;
			case '(':
				rz(L,choose);
				cout<<choose<<"Œ™◊Û¿®∫≈∏Æ£¨¥Ê»Î’ª∂•°£"<<endl;
				break;
			case ']':	
			    if(qzd(L)=='[')
			      cout<<cz(L,e)<<"∫Õ"<<choose<<"∆•≈‰≥…π¶£°"<<endl;
			    else
			      cout<<cz(L,e)<<"∫Õ"<<choose<<"∆•≈‰ ß∞‹£°"<<endl;
			      break;
			case ')':
				if(qzd(L)=='(') 
			      cout<<cz(L,e)<<"∫Õ"<<choose<<"∆•≈‰≥…π¶£°"<<endl;
			    else
			      cout<<cz(L,e)<<"∫Õ"<<choose<<"∆•≈‰ ß∞‹£°"<<endl;
			      break;
		}
		cin>>choose;
	}
}

int main()
{
	khpp();
	return 0;
}
