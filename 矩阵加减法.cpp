#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef struct
{
	int row,col,data;
}trible;


//trible data[MAXSIZE];
trible matrix1[MAXSIZE];
trible matrix2[MAXSIZE];
//trible ans[MAXSIZE];
int Arr1[20][20];
int Arr2[20][20];
int ans1[20][20];
int ans2[20][20];


int getmartix(trible* data) //��Ԫ�������
{
	int x,y,z;
	x=1; 
	int flag = 0; 
	for(int i = 0 ; x!=0 ; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		data[i].row = x;
		data[i].col = y;
		data[i].data = z;
		flag++;		
	}
	return flag;//������Ԫ��ĳ��� ������� 
}


void changematrix(trible* data1,trible*data2,int len1,int len2)//����Ԫ��Ԫ���޸�Ϊ���� 
{
	int p,q,m,n;
	for(int i = 0 ; i<len1-1 ; i++)
	{
		p=data1[i].row-1;
		q=data1[i].col-1;
		Arr1[p][q] = data1[i].data;
	}
	for(int j = 0 ; j<len2-1 ;j++)
	{
		m=data2[j].row-1;
		n=data2[j].col-1;
		Arr2[m][n] = data2[j].data;
	}
}


void plusmatrix(int a,int b)//������Ԫ����� ������뵽һ�������� 
{

	int p,q,m,n; 
	for(int i = 0 ; i<a ;i++)
	{
		for(int j = 0 ; j<b ;j++)
		{
			ans1[i][j] = Arr1[i][j]+Arr2[i][j];
		}
	}
}





void Subtraction(int a,int b)
{
	for(int i = 0 ; i<a ;i++)
	{
		for(int j = 0 ; j<b ;j++)
		{
			ans2[i][j] = Arr1[i][j]-Arr2[i][j];
		}
		
	}
}


void print2(int ans[20][20],int a,int b) //���������Ϻ������  
{
	for(int i = 0 ; i<a ;i++)
	{
		for(int j = 0 ; j<b ;j++)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}		
}


int main()
{
//	trible* ans;
	int rows,cols;
	int rows2,cols2;
	printf("�������������������������:\n"); 
	scanf("%d%d",&rows,&cols);
	scanf("%d%d",&rows2,&cols2);
	if((rows>rows2&&cols<cols2)||(rows<rows2&&cols>cols2)) 
	{
		printf("����������ƥ��");
		return 0; 
	}
	int rowsFinal=rows>rows2?rows:rows2;
	int colsFinal=cols>cols2?cols:cols2;
	
	for(int i = 0 ; i<rowsFinal; i++)
	{
		for(int j = 0 ;  j<colsFinal; j++)
		{
			ans1[i][j]=0;
		}
	}
	
	printf("�����һ��������Ԫ�飩��(����0 0 0����)\n");
	int len1 = getmartix(matrix1);
	printf("����ڶ���������Ԫ�飩��(����0 0 0����)\n");
	int len2 = getmartix(matrix2);
	changematrix(matrix1,matrix2,len1,len2);
	
	
	plusmatrix(rowsFinal,colsFinal);
	printf("...................................\n������Ӻ����£�\n");	
	print2(ans1,rowsFinal,colsFinal);
	Subtraction(rowsFinal,colsFinal);
	printf("...................................\n������������£�\n");
	print2(ans2,rowsFinal,colsFinal);
	
}

