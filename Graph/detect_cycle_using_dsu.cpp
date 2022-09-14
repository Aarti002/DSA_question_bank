#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findPar(int node,vector<int> &par)
{
    if(par[node]==node)
    return node;
    return par[node]=findPar(par[node],par);
}

void findUnion(int n1,int n2,vector<int> &par,vector<int> &rank){
    int p1=findPar(n1,par);
    int p2=findPar(n2,par);
    int r1=rank[p1];
    int r2=rank[p2];
    if(r1==r2)
    {
        par[p2]=p1;
        rank[p1]++;
    }
    else if(r1>r2)
    par[p2]=p1;
    else
    par[p1]=p2;
}

bool detect_cycle_dsu(vector<vector<int> > &adj,int n)
{
    vector<int> par(n),rank(n,0);
    for(int i=0;i<n;i++)
    par[i]=i;
    for(int i=0;i<n;i++){
        for(auto v:adj[i]){
            if(par[i]==par[v]){
                return true;
            }
            findUnion(v,i,par,rank);
        }
    }
    return false;
}

int main()
{
    int n,i,e,j;
    cin>>n>>e;
    vector<vector<int> > adj(n);
    while(e--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<detect_cycle_dsu(adj,n)<<endl;
    return 0;
}