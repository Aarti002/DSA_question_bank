#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//this algorithem is to find all articulation vertexes(those vertex whose removal will increase 
//number of components of given graph) 
//we are basically using three main vectors here a)parent[]--> to store parent vertex of each node
//b) discovering_time[]-->starting time or discovering time of particular node
//c) low[]-->finish time or lowest time amoung all its neighbour, for each node while backtracking

void dfs(int u,vector<vector<int> > &adj,int &t,vector<int> &vis,vector<int> &low,vector<int> &dis,vector<int> &par,vector<int> &art){
    vis[u]=1;
    dis[u]=low[u]=t;
    t++;
    int cnt=0;
    for(auto v:adj[u]){
        if(par[v]==u)
        continue;
        else if(vis[v])
        low[u]=min(low[u],dis[v]);
        else{
            par[v]=u;
            cnt++;
            dfs(v,adj,t,vis,low,dis,par,art);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dis[u])
            art[u]=1;
        }
    }
    if(par[u]==-1 && cnt>=2)
    art[u]=1;
}


int main(){
    int n,e,u,v;
    cin>>n>>e;
    vector<vector<int> > adj(n);
    while(e--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> art(n,0);
    vector<int> par(n);
    vector<int> low(n);
    vector<int> dis(n);
    int t=0;
    vector<int> vis(n,0);

    for(int i=0;i<n;i++){
        if(vis[i]==0)
         dfs(i,adj,t,vis,low,dis,par,art);
    }
   
    for(int i=0;i<n;i++)
    {
        if(art[i])
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}