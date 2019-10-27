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
		s->a[s->top];
		return 1;
	}
}
int Pop(seqstack *s,ptree x)
{
	if(Empty(s)) return 0;
	else {
		x=s->a[s->top];
		s->top--;
		return 1;
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
	if(temp == '#') return 0;
	else{
		root->data = temp;
		root->lchild = creat(root->lchild);
		root->rchild = creat(root->rchild);
	}
	return root;
}
void preorder(ptree root)
{
	seqstack *s;
	ptree p;
	s=InitStack();
	p=root;
	while(p!=NULL||!Empty(s))
	{
		while(p!=NULL)
		{
			printf("%c",p->data);
			Push(s,p);
			p=p->lchild;
		}
		if(!Empty(s))
		{
			Pop(s,p);
			p=p->rchild;
		}
	}
	return;
}
int main()
{
	ptree root;
	root = creat(root);
	preorder(root);
}
