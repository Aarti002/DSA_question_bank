#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isCyclic(vector<vector<int> > &adj,int u,vector<int> &vis)
{
    
    vis[u]=1;
    for(auto v:adj[u])
    {
        if(vis[v]==0 && isCyclic(adj,v,vis))
        {
            return true;
        }
        else if(v!=u)
        return true;
    }

    return false;
}

int longestCycle(vector<vector<int> > &adj,int n,vector<int> &edg)
{
    vector<int> vis(n,0),rep(n,0);
    int ans=INT_MIN,i;
    for(i=0;i<n;i++)
    {
        if(vis[i])
        continue;
        if(edg[i]==-1)
        continue;
        if(vis[i]==0 && isCyclic(adj,i,vis))
        {
            int cnt=1;
            int ind=i;
            while(i!=edg[ind]){
                cnt++;
            ind=edg[ind];
            }
            ans=max(ans,cnt);
        }
    }
    if(ans==INT_MIN)
    return -1;
    return ans;
}

int main()
{
    int n,e,i,u,v;
    cin>>n;
    vector<int> edg(n);
    vector<vector<int> > adj(n);
    for(i=0;i<n;i++)
    cin>>edg[i];
    for(i=0;i<n;i++)
    {
        u=i;
        v=edg[i];
        if(edg[i]!=-1)
        adj[v].push_back(u);
    }
    int ans=longestCycle(adj,n,edg);
    cout<<ans<<endl;

    return 0;

}