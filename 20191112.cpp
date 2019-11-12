#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef int DataType;
typedef struct node{/*结点类型定义*/
    DataType data;/*结点的数据域*/
    struct node *next;/*结点的指针域*/
}ListNode,*LinkList;
ListNode *p;
LinkList head;
/*注意：定义结点结构时，有几点需要注意：LinkList和ListNode *是不同名字的同一个指针类型，LinkList类型的指针变量head表示他是单链表的头指针，ListNode *类型的指针变量p表示它是指向某一结点的指针*/
LinkList InitList()
{
    LinkList L;
    L=(ListNode*)malloc(sizeof(ListNode));
    if(L==NULL)
    {
        printf("分配空间失败！");
        exit(1);
    }
    L->next=NULL;
    return L;
}
LinkList CreatListF()
{/*头插法建立单链表*/
    DataType x;
    LinkList L;
    ListNode *s;
    L=(ListNode *)malloc(sizeof(ListNode));/*头结点*/
    if(L==NULL)/*检查L是否分配到储存空间*/
    {
        printf("分配空间失败！");
        exit(1); 
    }
    L->next=NULL;
    scanf("%d",&x);
    while(x!=0)
    {
        s=(ListNode *)malloc(sizeof(ListNode));/*为新插入的结点申请空间*/
        if(s==NULL)
        {
            printf("分配空间失败！");
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
{/*尾插法建立单链表*/
    DataType x;
    LinkList L=(ListNode *)malloc(sizeof(ListNode));/*头结点*/
    if(L==NULL)
    {
        printf("分配空间失败！");
        exit(1);
    }
    ListNode *s,*r;
    r=L;
    scanf("%d",&x);
    while(x!=0)/*以0输入表示结束*/
    {
        s=(ListNode *)malloc(sizeof(ListNode));/*为新插入的结点申请空间*/
        if(s==NULL)
        {
            printf("分配空间失败！");
            exit(1);
        }
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;/*单链表的最后一个指针为空*/
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
        printf("查找的位置不正确！");
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
        printf("插入位置不正确！");
        exit(1);
    }
    s=(ListNode *)malloc(sizeof(ListNode));
    if(s==NULL)
    {
        printf("分配空间失败！");
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
        printf("删除位置不正确！");
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
    printf("链表元素如下：\n");
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
    printf("我们将采用头插法创建一个单链表L!\n请输入您要输入的数据（以空格隔开，以0结束！）\n");
    head=CreatListL();
    printf("单链表的长度为：%d\n",GetLength(head));
    printf("请输入您要查找元素的结点序号：");
    scanf("%d",&a);
    printf("第%d个元素为：%d\n",a,GetNode(head,a)->data);
    printf("请输入您要查找的元素：");
    scanf("%d",&a);
    printf("您查找的元素%d在链表中的第%d个位置\n",a,LocateListi(head,a));
    int x,i;
    printf("请输入您要插入元素的数值以及位置：");
    scanf("%d%d",&x,&i);
    InsertList(head,x,i);
    PrintList(head);
    printf("请输入您想要删除元素的位置：");
    scanf("%d",&i);
    DeleteList(head,i);
    PrintList(head);
    return 0;
}