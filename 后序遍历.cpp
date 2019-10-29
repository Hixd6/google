#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef struct tree
{
	char data;
	struct tree *lchild;
	struct tree *rchild;
}tree,*ptree;
typedef struct
{
	ptree a[MAXSIZE];
	int top;
}seqstack;
seqstack *InitStack()
{
	seqstack *s;
	s=(seqstack*)malloc(sizeof(seqstack));
	s->top = -1;
	return s;
}
int Empty(seqstack *s)
{
	if(s->top == -1) return 1;
	else return 0;
}
int Push(seqstack *s,ptree x)
{
	if(s->top == MAXSIZE -1) return 0;
	else{
		s->top++;
		s->a[s->top] = x;
		return 1;
	}
}
ptree Pop(seqstack *s)
{
	if(Empty(s)) return 0;
	else {
		ptree x;
		x=s->a[s->top];
		s->top--;
		return x;
		}
}
ptree GetTop(seqstack *s)
{
	if(Empty(s)) return 0;
	else return(s->a[s->top]);
}
ptree creat(ptree root)
{
	char temp;
	root=(ptree)malloc(sizeof(tree));
	scanf("%c",&temp);
	//getchar();
	if(temp == '#') return NULL;
	else{
		root->data = temp;
		root->lchild = creat(root->lchild);
		root->rchild = creat(root->rchild);
	}
	return root;
}
void aftorder(ptree root)
{
	seqstack* s;
	s=InitStack();
	ptree p,q;
	p=root;
	q=NULL;
	while(p!=NULL||!Empty(s))
	{
		while(p)
		{
			Push(s,p);
			p=p->lchild;
		}
		if(!Empty(s))
		{
			p=GetTop(s);
			if((p->rchild==NULL)||(p->rchild==q))
			{
				p=Pop(s);
				printf("%c",p->data);
				q=p;
				p=NULL;	
			}	
			else p=p->rchild;
		}
	}
}
int main()
{
	ptree root;
	root = creat(root);
	aftorder(root);
}
