#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void allPermutation(vector<int> &v,int n,set<vector<int> > &res,vector<int> &r,vector<int> &flag)
{
    if(r.size()==n)
    {
        res.insert(r);
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(flag[i]==0){
            flag[i]=1;
        r.push_back(v[i]);
        allPermutation(v,n,res,r,flag);
        r.pop_back();
        flag[i]=0;
        }
    }
    
}

void dfs(int &res,int n,int s,vector<vector<int> > &adj,vector<int> &time,vector<int> &vis,int &ans)
{
    vis[s]=1;
    res=max(res,ans);
    for(auto v:adj[s])
    {
        if(!vis[v])
        {
            ans+=time[s];
            dfs(res,n,v,adj,time,vis,ans);
            ans-=time[s];
        }
    }
}

void bfs(vector<vector<pair<int,int> > > &adj,int n,vector<int> &vis,int s)
{
    queue<pair<int,int> > q;
    vector<vector<int> > cost(n,vector<int>(2,-1));
    q.push({0,0});
    q.push({0,1});
    cost[0][0]=0;
    cost[0][1]=0;
    while(!q.empty())
    {
        int u=q.front().first;
        int c=q.front().second;
        q.pop();
        
        for(auto v:adj[u])
        {
            int v1=v.first;
            int c1=v.second;
            if(cost[v1][c1]!=-1 || c1==c )
            continue;
            cost[v1][c1]=cost[u][c]+1;
            q.push({v1,c1});
        }
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        sort(cost[i].begin(),cost[i].end());
        ans[i]=(cost[i][0]==-1?cost[i][1]:cost[i][0]);
    }
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
}

int main()
{
    int n,i,re,be,u,v;
    cin>>n>>re>>be;
    vector<int> vis(n,0);
    //min time as in one go parent node will cover all its child node
    vector<vector<pair<int,int> > > adj(n);
    while(re--)
    {
        cin>>u>>v;
        adj[u].push_back({v,0});
    }
    while(be--)
    {
        cin>>u>>v;
        adj[u].push_back({v,1});
    }
    bfs(adj,n,vis,0);
    
    return 0;
}