#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<int> *adj_lis;
    public:
        Graph(int v);
        void addEdegs(int u,int v);
        void dfs(vector<int> &v,int s);
        void bfs(int s);
        void allPaths(vector<vector<int> > &ans,vector<int> &temp,int s);
};
Graph::Graph(int v)
{
    this->v=v;
    adj_lis=new vector<int>[v];
}

void Graph::addEdegs(int u,int v)
{
    adj_lis[u].push_back(v);
}

void Graph::dfs(vector<int> &vis,int s)
{
    vis[s]=1;
    cout<<s<<" ";
    for(auto n:adj_lis[s])
    {
        if(vis[n]==0)
        dfs(vis,n);
    }
    return ;
}

void Graph::bfs(int s)
{
    queue<int> q;
    q.push(s);
    vector<int> vis(v,0);
    vis[s]=1;
    while(!q.empty())
    {
        int p=q.front();
        cout<<p<<" ";
        q.pop();
        for(auto x:adj_lis[p])
        {
            if(vis[x]==0)
            {
                vis[x]=1;
                q.push(x);
            }
        }
    }
    return ;
}

void Graph::allPaths(vector<vector<int> > &ans,vector<int> &temp,int s)
{
    if(s==v-1)
    {
        ans.push_back(temp);
        return ;
    }
    for(auto n:adj_lis[s])
    {
        temp.push_back(n);
        allPaths(ans,temp,n);
        temp.pop_back();
    }
    return ;
}

int main()
{
    int n,e,i,u,v;
    cin>>n>>e;
    Graph g(n);
    while(e--)
    {
        cin>>u>>v;
        g.addEdegs(u,v);
    }
    vector<int> vis(n,0);
    cout<<"DFS: ";
    g.dfs(vis,0);
    cout<<endl;
    cout<<"BFS: ";
    g.bfs(0);
    cout<<endl;
    cout<<"All possible paths from 0 node to n-1 node: ";
    vector<int> temp;
    vector<vector<int> > ans;
    g.allPaths(ans,temp,0);
    for(int i=0;i<ans.size();i++)
    {cout<<0<<" ";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}