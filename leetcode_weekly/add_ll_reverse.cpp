#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct ll{
int data;
struct ll *next;
};

struct ll* createLL(struct ll *s1,int x)
{
    struct ll *nn=new ll;
    nn->data=x;
    nn->next=NULL;
    if(s1==NULL)
    s1=nn;
    else{
        struct ll *temp=s1;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=nn;
    }  
    return s1;
}

struct ll* addLL(struct ll *s1,struct ll *s2)
{
    struct ll *t1=s1,*t2=s2,*pr1=NULL;
    int a,c=0;
    struct ll *nn=new ll;
    while(t1!=NULL && t2!=NULL)
    {
        a=t1->data+t2->data+c;
        c=a/10;
        a=a%10;
        t1->data=a;
        pr1=t1;
        t1=t1->next;
        t2=t2->next;
        
    }
    if(t1 || t2)
    {
        if(t2)
        pr1->next=t2;
        t1=pr1->next;
        while(t1)
        {
        a=t1->data+c;
        c=a/10;
        a=a%10;
        t1->data=a;
        pr1=t1;
        t1=t1->next;
        }
    }
    if(c>0)
    {
        struct ll *nn=new ll;
        nn->data=c;
        nn->next=NULL;
        pr1->next=nn;
    }
    return s1;
    
}

int main()
{
    int n,m,x;
    cin>>n;
    struct ll *s1=NULL,*s2=NULL;
    while(n--)
    {
        cin>>x;
        s1=createLL(s1,x);
    }
    cin>>m;
    while(m--)
    {
        cin>>x;
        s2=createLL(s2,x);
    }
    struct ll *final=addLL(s1,s2);
    struct ll *temp=final;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;

}