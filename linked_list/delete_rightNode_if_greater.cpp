#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node* createLL(struct node *head,int d)
{
    struct node *temp=new struct node;
    temp->data=d;
    temp->next=NULL;
    if(head==NULL)
    head=temp;
    else{
        struct node *p=head;
        while(p->next!=NULL)
        p=p->next;
        p->next=temp;
    }
    return head;
}

void printLL(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

struct node* removeLargeRight(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL && temp->next)
    {
        struct node *rr=temp->next;
        if(rr->data>temp->data){
        temp->data=rr->data;
        temp->next=rr->next;
        temp=head;
        }
        else
        temp=temp->next;
    }
    return head;
}

int main()
{
    int n,i,x;
    cin>>n;
    struct node *head=NULL;
    while(n--)
    {
        cin>>x;
        head=createLL(head,x);
    }
    printLL(head);
    cout<<endl;
    head=removeLargeRight(head);
    printLL(head);
    return 0;
}