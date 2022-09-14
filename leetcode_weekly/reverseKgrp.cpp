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

struct ll* reversell(struct ll *head,int k)
{

    struct ll *temp=head,*tp=head,*prev=NULL,*nxt=NULL;
    for(int i=0;i<k;i++)
    {
        if(tp==NULL)
        return head;
        tp=tp->next;
    }
    int cnt=0;
    while(temp!=NULL && cnt<k)
    {//cout<<temp->data<<" ";
        nxt=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxt;
        cnt++;
    }
    
    if(nxt)
    head->next=reversell(nxt,k);
    //head=prev;
    return prev;
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
    head=reversell(head,3);
    printll(head);
    return 0;
    
}