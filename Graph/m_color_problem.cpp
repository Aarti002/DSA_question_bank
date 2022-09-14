#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//here we are checking if it is possible to make graph bipirtite or not
bool checkBipirites(vector<vector<int> > &adj,int n)
{
    queue<int> q;
    vector<int> col(n,0);
    vector<int> vis(n,0);
    int i,j;
    for(int i=0;i<n;i++){
        q.push(i);
        col[i]=1;
    while(!q.empty())
    {
            int u=q.front();
            q.pop();
            if(vis[u]==1)
            continue;
            for(auto v:adj[u])
            {
                if(col[v]==col[u])
                return false;
                if(col[v]==0 && vis[v]==0)
                {
                    if(col[u]==1)
                    col[v]=2;
                    if(col[u]==2)
                    col[v]=1;
                    vis[v]=1;
                    q.push(v);
                }
            }
    }
    }
    return true;
}

bool isSecure(vector<vector<int> > &adj,int c,int u,vector<int> &col)
{
    for(auto v:adj[u])
    {
        if(col[v]==c)
        return false;
    }
    return true;
}

bool isPossibleColor(vector<vector<int> > &adj,int node,int n,int m,vector<int> &col)
{
    if(node==n)
    return true;

    for(int c=1;c<=m;c++)
    {
        if(isSecure(adj,c,node,col)){
        col[node]=c;
        if(isPossibleColor(adj,node+1,n,m,col))
        return true;
        col[node]=0;
        }
    }
    return false;
}



int main()
{
    int n,m,e,i,u,v;
    cin>>n>>m>>e;
    vector<vector<int> > adj(n);
    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    //bipirites graph
    vector<int> col(n,0);

    if(isPossibleColor(adj,0,n,m,col))
        cout<<"Yess\n";
    else
        cout<<"No\n";

    return 0;
}