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
LinkList Creat(int n)//����ѭ������ 
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
		printf("�������%d����Ա������",i);
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
	Rear->Next = NULL;
	return Head;
}
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
}
int main()
{
	int n; 
	printf("������ӵĳ���");
	scanf("%d",&n);
	LinkList L;
	L=Creat(n);
	Print_List(L);
}

