#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
	char data;
	struct tree *lchild;
	struct tree *rchild;
}tree,*ptree;
ptree creat(ptree root)
{
	int i = 0;
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
void preoutput(ptree root)
{
	if(root==NULL) return ;
	else{
		printf("%c",root->data);
		preoutput(root->lchild);
		preoutput(root->rchild);
	}
}
void inoutput(ptree root)
{
	if(root==NULL) return ;
	else{
		
		inoutput(root->lchild);
		printf("%c",root->data);
		inoutput(root->rchild);
	}
}
void postoutput(ptree root)
{
	if(root==NULL) return ;
	else{
		
		postoutput(root->lchild);
		postoutput(root->rchild);
		printf("%c",root->data);
	}
}
int main()
{
	ptree root;
	root = creat(root);
	preoutput(root);
	printf("\n");
	inoutput(root);
	printf("\n");
	postoutput(root);
}
