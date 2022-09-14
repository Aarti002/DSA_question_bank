#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &adj,int u,vector<int> &vis)
{
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v]==0)
        dfs(adj,v,vis);
    }
}

int main()
{
    int n,i,e;
    cin>>n>>e;
    vector<vector<int> > adj(n);
    while(e--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<vector<int> > ans(n);
    for(i=0;i<n;i++){
        vector<int> vis(n,0);
        dfs(adj,i,vis);
        for(int j=0;j<n;j++){
            if(vis[j]==1){
                ans[j].push_back(i);
           // cout<<j<<" ";
            }
        }
        //cout<<endl;
    }
    for(i=0;i<n;i++){
        cout<<i<<" : ";
        for(auto v:ans[i])
        cout<<v<<" ";
        cout<<endl;
    }
    return 0;
}