#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &adj,int s,int n,vector<int> &vis)
{
    vis[s]=1;
    cout<<s<<" ";
    for(auto it:adj[s])
    {
        if(!vis[it])
        dfs(adj,it,n,vis);
    }
    return ;
}

int main()
{
    int n,i;
    //cin>>n;
    vector<int> vis(4,0);
    vector<vector<int> > adj_lis(4);
    adj_lis[0]={1,2,0};
    adj_lis[1]={2};
    adj_lis[2]={0,1};
    adj_lis[3]={};
    dfs(adj_lis,0,4,vis);
    cout<<endl;
    if(find(vis.begin(),vis.end(),0)!=vis.end())
        cout<<"Not all rooms are visited!\n";
    else
    cout<<"All rooms are visited!\n";
    return 0;



}