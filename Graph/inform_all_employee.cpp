#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int mx=-1;
void dfs(vector<vector<int> > &adj,int n,int h,vector<int> &sir,vector<int> &time,vector<int> &vis,int &ans)
{
    vis[h]=1;
    mx=max(ans,mx);
    for(auto s:adj[h])
    {
        if(!vis[s])
        {
            ans+=time[h];
            dfs(adj,n,s,sir,time,vis,ans);
            ans-=time[h];
        }
    }
}

int main()
{
    int n,i,e,hid;
    cin>>n>>hid;
    vector<int> infotime(n),sir(n);
    for(i=0;i<n;i++)
    cin>>sir[i];
    for(i=0;i<n;i++)
    cin>>infotime[i];
    vector<vector<int> > adj_lis(n);
    for(i=0;i<n;i++)
    {
        if(sir[i]!=-1)
        adj_lis[sir[i]].push_back(i);
    }
    vector<int> vis(n,0);
    int ans=0;
    dfs(adj_lis,n,hid,sir,infotime,vis,ans);
    cout<<mx<<endl;
    return 0;

}