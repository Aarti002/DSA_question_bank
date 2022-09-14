#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct ll{
    int data;
    struct ll *next;
};

struct ll* craetell(struct ll *start,int data)
{
    struct ll *nn=new struct ll;
    nn->data=data;
    nn->next=NULL;
    struct ll *temp=start;
    if(start==NULL)
    start=nn;
    else{
        while(temp->next)
        temp=temp->next;
        temp->next=nn;
    }
    return start;
}

void printll(struct ll *start)
{
    struct ll *temp=start;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

struct ll* mergerkll(vector<struct ll*> &roots)
{
    priority_queue<int> pq;
    
    struct ll *nll=new struct ll;
    nll->data=0;
    nll->next=NULL;
    struct ll *nxt=nll;
    for(int i=0;i<roots.size();i++)
    {
        struct ll *n=roots[i];
        while(n)
        {
            pq.push(n->data);
            n=n->next;
        }
    }
    //cout<<endl<<"some left: ";
    while(!pq.empty())
    {
        int d=pq.top();
            pq.pop();
           // cout<<d<<" ";
            struct ll *nn=new struct ll;
            nn->data=d;
            nn->next=NULL;
            nll->next=nn;
            nll=nll->next;
    }
    return nxt->next;
}

int main()
{
    int n,i,j;
    cout<<"No of ll: ";
    cin>>n;
    cout<<"Provide size of each ll:";
    vector<int> v(n);
    vector<struct ll*> rs;
    for(i=0;i<n;i++)
    cin>>v[i];
    for(i=0;i<n;i++)
    {
        cout<<"data for new ll:";
        struct ll *nl=NULL;
        while(v[i]--){
            int x;  
            cin>>x;
            nl=craetell(nl,x);
        }
        printll(nl);
        cout<<endl;
        rs.push_back(nl);

    }
    struct ll *newll=mergerkll(rs);
    printll(newll);
    return 0;
}