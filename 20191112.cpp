#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef int DataType;
typedef struct node{/*������Ͷ���*/
    DataType data;/*����������*/
    struct node *next;/*����ָ����*/
}ListNode,*LinkList;
ListNode *p;
LinkList head;
/*ע�⣺������ṹʱ���м�����Ҫע�⣺LinkList��ListNode *�ǲ�ͬ���ֵ�ͬһ��ָ�����ͣ�LinkList���͵�ָ�����head��ʾ���ǵ������ͷָ�룬ListNode *���͵�ָ�����p��ʾ����ָ��ĳһ����ָ��*/
LinkList InitList()
{
    LinkList L;
    L=(ListNode*)malloc(sizeof(ListNode));
    if(L==NULL)
    {
        printf("����ռ�ʧ�ܣ�");
        exit(1);
    }
    L->next=NULL;
    return L;
}
LinkList CreatListF()
{/*ͷ�巨����������*/
    DataType x;
    LinkList L;
    ListNode *s;
    L=(ListNode *)malloc(sizeof(ListNode));/*ͷ���*/
    if(L==NULL)/*���L�Ƿ���䵽����ռ�*/
    {
        printf("����ռ�ʧ�ܣ�");
        exit(1); 
    }
    L->next=NULL;
    scanf("%d",&x);
    while(x!=0)
    {
        s=(ListNode *)malloc(sizeof(ListNode));/*Ϊ�²���Ľ������ռ�*/
        if(s==NULL)
        {
            printf("����ռ�ʧ�ܣ�");
            exit(1);
        }
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}
LinkList CreatListL()
{/*β�巨����������*/
    DataType x;
    LinkList L=(ListNode *)malloc(sizeof(ListNode));/*ͷ���*/
    if(L==NULL)
    {
        printf("����ռ�ʧ�ܣ�");
        exit(1);
    }
    ListNode *s,*r;
    r=L;
    scanf("%d",&x);
    while(x!=0)/*��0�����ʾ����*/
    {
        s=(ListNode *)malloc(sizeof(ListNode));/*Ϊ�²���Ľ������ռ�*/
        if(s==NULL)
        {
            printf("����ռ�ʧ�ܣ�");
            exit(1);
        }
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;/*����������һ��ָ��Ϊ��*/
    return L;
}
int GetLength(LinkList L)
{
    int num=0;
    ListNode *p;
    p=L->next;
    while(p!=NULL)
    {
        num++;
        p=p->next;
    }
    return(num);
}
ListNode *GetNode(LinkList L,int i)
{
    int j=1;
    ListNode *p;
    if(i<1||i>GetLength(L))
    {
        printf("���ҵ�λ�ò���ȷ��");
        exit(1);
    }
    p=L->next;
    while(p!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}
int LocateListi(LinkList L,DataType x)
{
    ListNode *p=L->next;
    int i=1;
    while(p!=NULL&&p->data!=x)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)
        return 0;
    else
        return i;
} 
void InsertList(LinkList L,DataType x,int i)
{
    ListNode *p,*q,*s;
    int j=1;
    p=L;
    if(i<1||i>GetLength(L)+1)
    {
        printf("����λ�ò���ȷ��");
        exit(1);
    }
    s=(ListNode *)malloc(sizeof(ListNode));
    if(s==NULL)
    {
        printf("����ռ�ʧ�ܣ�");
        exit(1);
    }
    s->data=x;
        while(j<=i)
        {
            q=p;
            p=p->next;
            j++;
        }
        s->next=p;
        q->next=s;
}
void DeleteList(LinkList L,int i)
{
    ListNode *p,*q;
    int j=1;
    p=L;
    if(i<1||i>GetLength(L))
    {
        printf("ɾ��λ�ò���ȷ��");
        exit(1);
    }
    while(j<i)
    {
        p=p->next;
        j++;
    }
    q=p->next;
    p->next=q->next;
    free(q);
}
void PrintList(LinkList L)
{
    ListNode *p;
    p=L->next;
    printf("����Ԫ�����£�\n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    DataType a;
    head=InitList();
    printf("���ǽ�����ͷ�巨����һ��������L!\n��������Ҫ��������ݣ��Կո��������0��������\n");
    head=CreatListL();
    printf("������ĳ���Ϊ��%d\n",GetLength(head));
    printf("��������Ҫ����Ԫ�صĽ����ţ�");
    scanf("%d",&a);
    printf("��%d��Ԫ��Ϊ��%d\n",a,GetNode(head,a)->data);
    printf("��������Ҫ���ҵ�Ԫ�أ�");
    scanf("%d",&a);
    printf("�����ҵ�Ԫ��%d�������еĵ�%d��λ��\n",a,LocateListi(head,a));
    int x,i;
    printf("��������Ҫ����Ԫ�ص���ֵ�Լ�λ�ã�");
    scanf("%d%d",&x,&i);
    InsertList(head,x,i);
    PrintList(head);
    printf("����������Ҫɾ��Ԫ�ص�λ�ã�");
    scanf("%d",&i);
    DeleteList(head,i);
    PrintList(head);
    return 0;
}