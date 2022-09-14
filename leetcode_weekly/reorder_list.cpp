#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct ll{
int data;
struct ll *next;
};

struct ll* createll(struct ll *head,int data)
{
    struct ll *node=new struct ll;
    node->data=data;
    node->next=NULL;
    if(head==NULL)
    head=node;
    else{
        struct ll *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=node;
    }
    return head;
}

void printll(struct ll *head)
{
    struct ll *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

struct ll* reversell(struct ll *head)
{
    struct ll *temp=head,*prev=NULL,*nxt=NULL;
    while(temp!=NULL)
    {//cout<<temp->data<<" ";
        nxt=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxt;
    }
    head=prev;
    return head;
}

struct ll* reorderList(struct ll *head)
{
    int sz=0;
    struct ll *temp=head;
    while(temp!=NULL)
    {
        sz++;
        temp=temp->next;
    }
    int half=0;
    struct ll *s1=head,*s2=NULL;
    while(half<(sz/2))
    {
        half++;
        s1=s1->next;
    }
    
    s2=s1->next;
    s1->next=NULL;
   // printll(head);
    //printll(s2);
    s2=reversell(s2);
    printll(s2);
    struct ll *t1=head,*t2=s2,*n1=NULL,*n2=NULL;
    while(t1!=NULL && t2!=NULL)
    {
        n1=t1->next;
        n2=t2->next;
        t1->next=t2;
        t2->next=n1;
        t1=n1;
        t2=n2;
    }
    return head;

}

int main()
{
    int n,i,j,x;
    cin>>n;
    struct ll *head=NULL;
    while(n--)
    {
        cin>>x;
        head=createll(head,x);
    }
  //  printll(head);
    head=reorderList(head);
    printll(head);
    return 0;
    
}