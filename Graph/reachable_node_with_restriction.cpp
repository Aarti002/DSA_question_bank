#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs_with_restrictions(vector<vector<int>> &adj,int n,vector<int> &res)
{
    vector<int> vis(n,0);
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v:adj[u])
        {
            if(vis[v]==0 && find(res.begin(),res.end(),v)==res.end()){
                vis[v]=1;
                q.push(v);
            }
        }
    }
}

void dfs(vector<vector<int> > &adj,int u,int &cnt,vector<int> &vis)
{
    vis[u]=1;
    cnt++;
    for(auto v:adj[u])
    {
        if(vis[v]==0)
        dfs(adj,v,cnt,vis);
    }
}

int main()
{
    int n,e,u,v,r,i;
    cin>>n>>e;
    vector<vector<int> > adj(n);
    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>r;
    vector<int> rest(r);
    vector<int> vis(n,0);
    for(i=0;i<r;i++){
    cin>>rest[i];
    vis[rest[i]]=1;
    }
    
    int cnt=0;
    dfs(adj,n,cnt,vis);
    cout<<cnt<<" -Total visited node avoiding restricted node.\n";


    return 0;
}