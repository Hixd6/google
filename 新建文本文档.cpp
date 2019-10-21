#include <stdio.h>
#define MAXSIZE 7
typedef struct
{
	int row,col;
	int value;
 } triple;
 typedef struct
 {
 	triple data[MAXSIZE];
 	//int rows,cols,nums;
 }tsmatrix;
 void print(tsmatrix* a)
 {
 	for(int j  = 0 ;j<MAXSIZE ; j++)
	{
		printf("%d ",a->data[j]->col);
		printf("%d ",a->data[j]->row);
		printf("%d\n",a->data[j]->value);	
	}
 }
 void input(tsmatrix* a)
 {
 	int x,y,z;
 	for(int i = 0 ; i<MAXSIZE ; i++)
	{
	printf("input matrix's row col value\n");
	scanf("%d%d%d",&x,&y,&z);
	a.data[i]->row=y;
	a.data[i]->col=x;
	a.data[i]->value =z;
	}
 }
int main()
{
	tsmatrix a;
	tsmatrix *p;
	p=&a;
	input(P);
	print(p);
}
