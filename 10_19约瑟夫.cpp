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
	printf("������Ҫ����������:");
	scanf("%d",&n);
	head = (node*)malloc(sizeof(node));
	//head->next=NULL;
	p=head;
	for(int i = 1 ; i<n ;i++)
	{
		
		printf("�����%d���ڵ�����룺",i);
		scanf("%d",&pass);
		p->password = pass;
		p->num = i;
		p->next = (node*)malloc(sizeof(node));
		p=p->next;
	}
	//p=(node*)malloc(sizeof(node));
	printf("�����%d���ڵ�����룺",n);
	p->num = n;
	scanf("%d",&pass);
	p->password = pass;
	p->next=head;
	return head;
}
void show_list(pnode head)//�������Ԫ��
{
	pnode p=head;
	if(p==NULL)
	{
		printf("���κ�Ԫ��\n");
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
	
	printf("�����ʼ����:");
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
pnode Get(pnode head)//��ʼ��ȡ����
{
	int n,i;
	pnode p=head;
	pnode q=head;
	if(head==NULL)
	{
		printf("���κ���\n");
		return NULL;
	}
	printf("�����ʼ����:");
	scanf("%d",&n);
	while(n<=1)
	{
		printf("����Ϊ2\n");
		scanf("%d",&n);
	}

	if(head->next==head)//���ֻ��һ��Ԫ��
	{
		printf("%d",head->num);
		return head;
	}
	do
	{
		for(i=1;i<n;i++)//ѭ��n�� 
		{
			q=p;
			p=p->next;//ʹp�ߵ����һλ�ڵ㴦 
		}
		q->next=p->next;
		printf("%d\t",p->num);//������
		n=p->password;//�µ�����
		free(p);//�ͷŸýڵ�
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

