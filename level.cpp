#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 200
#define QUEUEDATA treenode*
//#define TREEDATA char
typedef struct tree
{
	struct tree* lchild;
	char data;
	struct tree* rchild;
}treenode,*ptree;
typedef struct
{
	QUEUEDATA data[MAXSIZE];
	int rear,front;
}queue;

queue* Initqueue(queue* q)
{
	q=(queue*)malloc(sizeof(queue));
	q->rear=0;
	q->front=0;
	return q;
}

bool addqueue(queue* q,treenode* temp)
{
//	treenode* temp=(treenode*)malloc(sizeof(treenode));
	if(q->rear>MAXSIZE) return false;
	else
	{
		q->data[q->rear]=temp;//
		q->rear++;
		return true;
	}
}
treenode* outqueue(queue* q)
{
	if(q->rear==q->front) return NULL;
	//temp=(treenode*)malloc(sizeof(treenode));
	else
	{
		treenode* temp;
		temp=q->data[q->front];
//		printf("*%c\n",q->data[q->front]);
		q->front++;
		return temp;
	}
}
bool empty(queue* q)
{
	if(q->rear==q->front) return true;
	else return false;
}
//
//treenode* creat(treenode* root)
//{
//	char temp;
//	root=(treenode*)malloc(sizeof(treenode));
//	scanf("%c",&temp);
//	if(temp == '#')	return 0;
//	else
//	{
//		root->data=temp;
//		root->lchild=creat(root->lchild);
//		root->rchild=creat(root->rchild);
//	}
//	return root;
//}

treenode* creat(treenode* root)
{
	char temp;
	root=(treenode*)malloc(sizeof(treenode));
//	temp=getche();
	scanf("%c",&temp);
	//getchar();
	if(temp == '#') return 0;
	else{
		root->data = temp;
		root->lchild = creat(root->lchild);
		root->rchild = creat(root->rchild);
	}
	return root;
}

void level(treenode* root,queue* q)
{
	treenode* p = (treenode*)malloc(sizeof(treenode));
	p = root;
	addqueue(q,p);
	treenode* temp;
	//treenode* temp=(treenode*)malloc(sizeof(treenode));
	while(!empty(q))
	{
		temp=outqueue(q);
		printf("%c",temp->data);
		if(temp->lchild!=NULL)
		{
			addqueue(q,temp->lchild);
//			printf("%c\n",q->data);
		}
		if(temp->rchild!=NULL)
		{
			addqueue(q,temp->rchild);
//			printf("%c\n",q->data);
		}
	}
}

int main()
{
	treenode* root;
	root=creat(root);//root=
	queue* q;
	q=Initqueue(q);
	level(root,q);
	
	
}
