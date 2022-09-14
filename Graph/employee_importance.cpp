#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int id;
    int importance;
    vector<int> subord;
};

struct node* newNode(int id,int imp,vector<int> &so){
    struct node *n=new struct node;
    n->id=id;
    n->importance=imp;
    n->subord=so;
    return n;
}

void dfs(vector<vector<int> > &adj,int n,int id,int &ans,vector<int> &vis,vector<int> &imp){
    vis[id]=1;
    ans+=imp[id];
    for(auto v:adj[id]){
        if(vis[v]==0){
            dfs(adj,n,v,ans,vis,imp);
        }
    }
}

int total_importance(vector<vector<int>> &adj,int n,int k,vector<int> &imp)
{
    int ans=0;
    vector<int> vis(n,0);
    dfs(adj,n,k,ans,vis,imp);
    return ans;
}

int main()
{
    int n,i,m,k;
    cin>>n>>k;
    int id,imp,subor;
    vector<struct node*> nodes(n);
    
    for(i=0;i<n;i++){
        
        cout<<"Enter importance and no. of subordinate: ";
        cin>>imp>>m;
        vector<int> v(m);
        if(m>0){
        cout<<"Enter subordinates:";
        for(int j=0;j<m;j++)
        cin>>v[j];
        }
        struct node *d=newNode(i,imp,v);
        nodes[i]=d;
    }
    vector<int> with_imp(n);
    for(i=0;i<n;i++){
        cout<<nodes[i]->id<<" "<<nodes[i]->importance<<" [";
        vector<int> t=nodes[i]->subord;
        for(int j=0;j<t.size();j++)
        cout<<t[j]<<" ";
        cout<<"]\n";
        with_imp[i]=nodes[i]->importance;
    }
    vector<vector<int> > adj(n);
    for(i=0;i<n;i++){
        vector<int> so=nodes[i]->subord;
        for(auto v:so){                     //adding edges
            adj[i].push_back(v);
        }
    }
    
    int ans=total_importance(adj,n,k,with_imp);
    cout<<"Total importance: "<<ans<<endl;




    return 0;
}