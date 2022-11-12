#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define MaxSize 100
#define ElemType int
#define Status int
using namespace std;
//顺序表数据结构
typedef struct
{
    ElemType data[MaxSize];//顺序表元素
    int length;            //顺序表当前长度
}SqList;
//***************************基本操作函数*******************************//
//初始化顺序表函数，构造一个空的顺序表 
Status InitList(SqList &L)
{
    memset(L.data,0,sizeof(L));//初始化数据为0
    L.length=0;                //初始化长度为0
    return 0;
}
//创建顺序表函数 初始化前n个数据
bool CreatList(SqList &L,int n)
{
    if(n<0||n>MaxSize)false;//n非法
    for(int i=0;i<n;i++)
    {
        scanf("%d",&L.data[i]);
        L.length++;
    }
    return true;
}
//插入函数 位置i插入数据 i及之后元素后移  1=<i<=length+1 
bool InsertList(SqList &L,int i,ElemType e)
{
    if(i<1||i>L.length+1) //判断位置是否有效
     {
        printf("位置无效！！！\n");
        return false;
     }
    if(L.length>=MaxSize)//判断存储空间是否已满
    {
        printf("当前存储空间已满！！！\n");
        return false;
    }
    for(int j=L.length;j>=i;j--)//位置i及之后元素后移
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}
//删除函数 删除位置i的元素 i之后的元素依次前移
bool  ListDelete(SqList &L,int i)
{
    if(i<1||i>L.length)
     {
        printf("位置无效！！！\n");
        return false;
     }
    for(int j=i;j<=L.length-1;j++)//位置i之后元素依次前移覆盖
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}
//查找函数 按位置从小到大查找第一个值等于e的元素 并返回位置
int LocateElem(SqList L,ElemType e)
{
 for(int i=0;i<L.length;i++)//从低位置查找
    {
        if(L.data[i]==e)
            return i+1;
    }
 return 0;
 
}
//********************************功能函数*****************************************//
//输出功能函数 按位置从小到大输出顺序表所有元素
void PrintList(SqList L)
{
    printf("当前顺序表所有元素:");
    for(int i=0;i<L.length;i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}
//创建顺序表函数
void Create(SqList &L)
{
    int n;bool flag;
    printf("请输入要创建的顺序表长度(>1):");
    scanf("%d",&n);
    printf("请输入%d个数（空格隔开）:",n);
    flag=CreatList(L,n);
    if(flag){
        printf("创建成功！\n");
        PrintList(L);
    }
    else printf("输入长度非法！\n");
 
}
//插入功能函数 调用InsertList完成顺序表元素插入 调用PrintList函数显示插入成功后的结果
void Insert(SqList &L)
{
  int place;ElemType e;bool flag;
  printf("请输入要插入的位置(从1开始)及元素:\n");
  scanf("%d%d",&place,&e);
  flag=InsertList(L,place,e);
  if(flag) 
  {
    printf("插入成功！！！\n");
    PrintList(L);
  }
}
//删除功能函数 调用ListDelete函数完成顺序表的删除 调用PrintList函数显示插入成功后的结果
void Delete(SqList &L)
{
  int place;bool flag;
  printf("请输入要删除的位置(从1开始):\n");
  scanf("%d",&place);
  flag=ListDelete(L,place);
  if(flag) 
  {
    printf("删除成功！！！\n");
    PrintList(L);
  }
}
//查找功能函数 调用LocateElem查找元素
void Search(SqList L)
{
  ElemType e;int flag;
  printf("请输入要查找的值:\n");
  scanf("%d",&e);
  flag=LocateElem(L,e);
  if(flag) 
  {
    printf("该元素位置为:%d\n",flag);
  }
  else
      printf("未找到该元素！\n");
}
//菜单
void menu()
{
   printf("********1.创建    2.插入*********\n");
   printf("********3.删除    4.查找*********\n");
   printf("********5.输出    6.退出*********\n");
}
int main()
{
 SqList L;int choice;
 InitList(L);
 while(1)
 {
  menu();
  printf("请输入菜单序号：\n");
  scanf("%d",&choice);
  if(6==choice) break;
  switch(choice)   
  {
  case 1:Create(L);break;
  case 2:Insert(L);break;
  case 3:Delete(L);break;
  case 4:Search(L);break;
  case 5:PrintList(L);break;
  default:printf("输入错误！！！\n");
  }
 }
 return 0;
}

