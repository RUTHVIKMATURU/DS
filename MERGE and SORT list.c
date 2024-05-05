#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
typedef struct node NODE;
NODE *p1,*p2,*p3;
NODE *insert()
{
    int ch;
    NODE *newnode,*first=NULL,*temp;
    do{
    newnode=(NODE*)malloc(sizeof(NODE));
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    if(first==NULL)
    {
        first=newnode;
        temp=newnode;
    }
    else
    {
        temp->link=newnode;
        temp=temp->link;
    }
    printf("Enter 1 to continue else 0:");
    scanf("%d",&ch);
    }while(ch==1);
    return (first);
}
void add()
{
    NODE *temp=p1;
    p3=p1;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=p2;
}
void display()
{
    NODE *temp=p3;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("NULL\n");
}
void sort()
{
    NODE *temp1,*temp2;
    temp1=p3;
    int t;
    while(temp1!=NULL)
    {
        temp2=temp1;
        while(temp2!=NULL)
        {
            if(temp1->data>=temp2->data)
            {
                t=temp1->data;
                temp1->data=temp2->data;
                temp2->data=t;
            }
            temp2=temp2->link;
        }
        temp1=temp1->link;
    }
}
int main()
{
    printf("Enter first list:");
    p1=insert();
    printf("Enter second list:");
    p2=insert();
    add();
    printf("Merged list:\n");
    display();
    sort(p3);
    printf("The sorted list :\n");
    display();
    return 0;
}
