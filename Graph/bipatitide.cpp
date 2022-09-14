#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isBiparitited(vector<vector<int> > &adj,int n)
{
    queue<int> q;
    vector<int> color(n,0);
    for(int i=0;i<n;i++)
    {
        if(color[i]==0){
        q.push(i);
        color[i]=1;
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            for(auto x:adj[v])
            {
                if(color[x]==color[v])
                return false;
                if(color[x]==0)
                {
                    if(color[v]==1)
                    color[x]=2;
                    if(color[v]==2)
                    color[x]=1;
                    q.push(x);
                }
            }
        }
        }
    }
    return true;
}

int main()
{
    int n,i,e,u,v;
    cin>>n>>e;
    vector<vector<int> > adj(n);
    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<isBiparitited(adj,n);
    return 0;

}