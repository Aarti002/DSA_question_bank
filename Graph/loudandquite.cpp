#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void topological_sort(vector<vector<int> > &edg,int n,vector<int> &ind,vector<int> &ts,vector<int> &qut)
{
    queue<int> q;
    for(int i=0;i<n;i++)
    {ts[i]=i;
        if(ind[i]==0)
        q.push(i);
    }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
      //  ts.push_back(u);
        for(auto v:edg[u])
        {
            ind[v]--;
            if(ts[v]==INT_MAX || qut[ts[u]]>qut[ts[v]])
            ts[v]=ts[u];
            if(ind[v]==0)
            q.push(v);
        }
    }
}

int main()
{
    int n,e,i,u,v;
    cin>>n>>e;
    vector<vector<int> > edg(n);
    vector<int> q(n);
    vector<int> indeg(n,0);
    while(e--)
    {
        cin>>u>>v;
        edg[u].push_back(v);
        indeg[v]++;
    }
    for(i=0;i<n;i++)
    cin>>q[i];
    vector<int> ts(n,INT_MAX);
    topological_sort(edg,n,indeg,ts,q);       //to find rich node first
    for(i=0;i<n;i++)
    cout<<ts[i]<<" ";
    return 0;

}