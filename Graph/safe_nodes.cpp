#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPath(vector<vector<int> > &adj_lis,int s,vector<int> &vis)
{
    if(vis[s]>0)
    vis[s]=2;
    vis[s]=1;
    for(auto p:adj_lis[s])
    {
        if(vis[p]==2)
        continue;
        if(vis[p]==1 || !isPath(adj_lis,p,vis))
        return false;
    }
    vis[s]=2;
    return true;
}

int main()
{
    int n,m,e,i,j,u,v;
    cin>>n>>e;
    vector<vector<int> > adj_lis(n);
    while(e--)
    {
        cin>>u>>v;
        adj_lis[u].push_back(v);
    }
    vector<int> terminal_node;
    for(i=0;i<n;i++)
    {
        if(adj_lis[i].size()==0){
        //cout<<i<<" ";
        terminal_node.push_back(i);
        }
    }
    vector<int> ans;
    
   vector<int> vis(n,0);
    for(i=0;i<n;i++)
    {
        if(isPath(adj_lis,i,vis))
        ans.push_back(i);
    }
    
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;

    

}