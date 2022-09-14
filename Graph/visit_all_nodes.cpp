#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &edg,int n,vector<int> &vis,int s,int &cnt)
{
    if(s==n)
    return ;
    vis[s]=1;
    cout<<s<<endl;
    for(auto node:edg[s])
    {
        if(vis[node]==0){
            cnt++;
          dfs(edg,n,vis,node,cnt);
        }
        
    }
    vis[s]=0;
    return ;
}

int main()
{
    int n,i,e,u,v;
    cin>>n>>e;
    vector<vector<int> > edg(n);
    while(e--)
    {
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    vector<int> vis(n,0);
    int cnt=0;
    dfs(edg,n,vis,0,cnt);
    cout<<cnt<<endl;
return 0;

}