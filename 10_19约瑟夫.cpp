#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node
{
	int num;
	int password;
	struct node *next;
}node,*pnode;
pnode creat(pnode head)
{
	int pass,n; 
	pnode p = NULL;
	printf("请输入要创建的人数:");
	scanf("%d",&n);
	head = (node*)malloc(sizeof(node));
	//head->next=NULL;
	p=head;
	for(int i = 1 ; i<n ;i++)
	{
		
		printf("输入第%d个节点的密码：",i);
		scanf("%d",&pass);
		p->password = pass;
		p->num = i;
		p->next = (node*)malloc(sizeof(node));
		p=p->next;
	}
	//p=(node*)malloc(sizeof(node));
	printf("输入第%d个节点的密码：",n);
	p->num = n;
	scanf("%d",&pass);
	p->password = pass;
	p->next=head;
	return head;
}
void show_list(pnode head)//输出链表元素
{
	pnode p=head;
	if(p==NULL)
	{
		printf("无任何元素\n");
		return ;
	}
	if(head->next==head)
	{
		printf("%d\n",head->password);
		return ;
	}
	while(p->next!=head)
	{
		printf("%d\t",p->password);
		p=p->next;
	}
	printf("%d\t",p->password);
	printf("\n");
}/*
pnode get(pnode head)
{
	int p,i=1;
	pnode cur=head;
	pnode rear=head;
	
	printf("输入初始密码:");
	scanf("%d",&p);
		while(cur->next!=cur)
			{
				while(rear->next!=cur)
				{
					rear=rear->next;
				}
				cur=cur->next;
				rear=rear->next;
				i++;
				if(i==p)
				{
					rear->next = cur->next;
					free(cur);
					printf("%d ",cur->num);
					cur=rear->next;
					p=cur->password;
				}
			}
		}*/
pnode Get(pnode head)//开始获取密码
{
	int n,i;
	pnode p=head;
	pnode q=head;
	if(head==NULL)
	{
		printf("无任何人\n");
		return NULL;
	}
	printf("输入初始密码:");
	scanf("%d",&n);
	while(n<=1)
	{
		printf("至少为2\n");
		scanf("%d",&n);
	}

	if(head->next==head)//如果只有一个元素
	{
		printf("%d",head->num);
		return head;
	}
	do
	{
		for(i=1;i<n;i++)//循环n次 
		{
			q=p;
			p=p->next;//使p走到最后一位节点处 
		}
		q->next=p->next;
		printf("%d\t",p->num);//输出序号
		n=p->password;//新的密码
		free(p);//释放该节点
		p=q->next;
	}while(p->next!=p);
	printf("%d\t",p->num);
	return p;
}
int main()
{
	int n;
	pnode head;
	head=creat(head);
	show_list(head);
	Get(head);
	return 0;
}

