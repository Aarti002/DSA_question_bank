#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//kasaraju's algo
//1>. arrange nodes in order of their finish time i.e when we are done with visiting all adjacent 
//node of a particular node --->put each node in stack(reverse_dfs)
//2>. reverse each edge i.e u---->v to v---->u
//3>. perform dfs on new reversed edged graph 
void reverse_dfs(vector<vector<int> > &adj,int u,vector<int> &vis,stack<int> &path)
{
    vis[u]=1;
    for(auto v:adj[u])
    {
        if(vis[v]==0){
        reverse_dfs(adj,v,vis,path);
        }
    }
    path.push(u);
}

void dfs(vector<vector<int> > &adj,int u,vector<int> &vis)
{
    vis[u]=1;
    cout<<u<<" ";
    for(auto v:adj[u])
    {
        if(vis[v]==0)
        dfs(adj,v,vis);
    }
}

int main()
{
    int n,e,u,v,i;
    cin>>n>>e;
    vector<vector<int> > adj(n);
    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int cnt=0;
    vector<int> vis(n,0);
    stack<int> path;
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            reverse_dfs(adj,i,vis,path);
        }
    }
    vector<vector<int> > rev_edg(n);
    for(i=0;i<n;i++){
        for(auto v:adj[i])
        {
            rev_edg[v].push_back(i);
        }
    }

    vector<int> vis_no(n,0);
    while(!path.empty())
    {
       // cout<<path.top()<<" ";
       int x=path.top();
        if(vis_no[x]==0)
        dfs(rev_edg,x,vis_no);
        cout<<endl;
        path.pop();
    }
  //  cout<<cnt<<endl;
    return 0;
}