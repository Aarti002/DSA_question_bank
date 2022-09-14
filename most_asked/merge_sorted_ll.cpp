#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node* createll(struct node *head,int data)
{
    struct node *n=new struct node;
    n->data=data;
    n->next=NULL;
    if(head==NULL)
    head=n;
    else{
        struct node *temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=n;
    }
    return head;
}

void printll(struct node *head)
{
    /* data */
    struct node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
cout<<endl;
}

struct node* mergell(struct node *h1,struct node *h2)
{
    /* data */
    struct node *nn=new struct node;
    struct node *t=nn;
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data>h2->data)
        {
            t->next=h2;
            h2=h2->next;
        }
        else{
            t->next=h1;
            h1=h1->next;
        }
        t=t->next;
    }
    if(h1!=NULL)
    t->next=h1;
    else
    t->next=h2;
    return nn->next;
}

int main()
{
    int n,m,i,x;
    cin>>n;
    struct node *h1=NULL,*h2=NULL;
    while(n--)
    {
        cin>>x;
        h1=createll(h1,x);
    }
    printll(h1);
    cin>>m;
    while(m--)
    {
        cin>>x;
        h2=createll(h2,x);
    }
    printll(h2);
    printll(mergell(h1,h2));
    return 0;
}