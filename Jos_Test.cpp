#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct Node
{
	int num;
	int password;
	struct Node *Next;
}ListNode,*LinkList;
void List_Int()
{
	LinkList Head =NULL;	
} 
LinkList Creat(int n)//创建循环链表 
{
	int password;
	LinkList Head;
	Head =NULL;
	ListNode *Rear;
	Rear = NULL;
	ListNode *pNew;
	for(int i = 1 ; i <= n;i++)
	{
		pNew=(LinkList)malloc(sizeof(ListNode));
		pNew->num = i;
		printf("请输入第%d个队员的密码：",i);
		scanf("%d",&password);
		pNew->password = password;
		if(Head==NULL)
		{
			Head = pNew;
			Rear = pNew;
			pNew->Next = NULL;
		}
		else
		{
			Rear->Next = pNew;
			Rear = pNew;
		}
	}
	Rear->Next = Head;
	return Head;
}
/*
void Print_List(LinkList L)
{
	ListNode *p;
	p=L;
	while(1) 
	{
		printf("(%d ",p->num);
		printf("%d)",p->password);
		if(p->Next==NULL) break;
		p=p->Next;
		
	}
}*/
int Deal(LinkList Head,int m)
{
	int i = 0;
	ListNode *Flag,*Front,*Rear;
	Rear=Head;
	Flag=Head;//判出 
	Front=Head;
	while(Rear->Next!=Flag)//建立尾指针跟随处理的指针 
	{
		Rear=Rear->Next;
	}
	while(1){
	while(i<=m)
	{
		/*if(i==m)
		{
			if(Front==Flag) return 0;
			Rear->Next = Front->Next;
			free(Front);
			Deal(Front->Next,Front->password);
			printf("%d ",Front->num);
		}*/
		i++;
		Front=Front->Next;
		Rear=Rear->Next;
	}
	m=Front->password;
	i=0;
	printf("%d",Front->password);
	Flag=Front->Next;
	if (Front==Flag) return 0;
	Rear->Next=Front->Next;
	free(Front);
	
	}
}
int main()
{
	int m,n; 
	printf("请输入队的长度：");
	scanf("%d",&n); 
	printf("请输入初始密码：");
	scanf("%d",&m);
	LinkList L;
	L=Creat(n);
	Deal(L,m);
	//Print_List(L);
}

