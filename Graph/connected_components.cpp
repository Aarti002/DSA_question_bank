#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<int> *adjlis;
    public:
        Graph(int v);
        void add_edges(int u,int v);
        void display();
        void dfs(vector<int> &vis,int s);
        int connected_components();
};

Graph::Graph(int v)
{
    this->v=v;
    adjlis=new vector<int>[v];
}

void Graph::add_edges(int u,int v)
{
    adjlis[u].push_back(v);
    adjlis[v].push_back(u);
}

void Graph::dfs(vector<int> &vis,int s)
{
    vis[s]=1;
    for(int i=0;i<adjlis[s].size();i++)
    {
        if(!vis[adjlis[s][i]])
        dfs(vis,adjlis[s][i]);
    }
}

void Graph::display()
{
    for(int i=0;i<v;i++)
    {
        cout<<"for node "<<i<<" : ";
        for(int j=0;j<adjlis[i].size();j++)
        cout<<adjlis[i][j]<<" ";
        cout<<endl;
    }
}

int Graph::connected_components()
{
    int i,cnt=0;
    vector<int> vis(v,0);
    for(i=0;i<v;i++)
    {
        if(!vis[i]){
        dfs(vis,i);
        cnt++;
        }
    }
    return cnt;
}


int main()
{
    int n,i,e;
    cin>>n;
    cin>>e;
    Graph g(n);
    int u,v;
    cout<<"Enter edge node: ";
    while(e--)
    {
        cin>>u>>v;
        g.add_edges(u,v);
    }
    g.display();
    int ans=g.connected_components();
    cout<<"Total components in this graph: "<<ans<<endl;
    return 0;
}