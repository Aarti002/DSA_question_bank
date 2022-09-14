#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<pair<int,int> > *adj_lis;
    //vector<vector<int> > *wgt;
    public:
        Graph(int v);
        void add_edge(int u,int v,int w);
        void bfs(int s);
        vector<int> dijikstra_algo(int s);
};

Graph::Graph(int v)
{
    this->v=v;
    adj_lis=new vector<pair<int,int> > [v];
    //this->wgt=new vector<vector<int> > (v+1,vector<int>(v+1,0));
}

void Graph::add_edge(int u,int v,int w)
{
    adj_lis[u].push_back(make_pair(v,w));
    adj_lis[v].push_back(make_pair(u,w));
   // wgt[u][v]=w;
    //wgt[v][u]=w;
}

void Graph::bfs(int s)
{
    vector<int> vis(v,0);
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        cout<<p<<" ";
        vector<pair<int,int> > ::iterator it;
        for(it=adj_lis[p].begin();it!=adj_lis[p].end();it++)
        {
            int v=it->first;
            int w=it->second;
            if(vis[v]==0)
            {
                q.push(v);
                vis[v]=1;
            }
        }
    } 
    cout<<endl;
}
 
vector<int> Graph::dijikstra_algo(int s)
{
    vector<int> dis(v,INT_MAX);
    dis[s]=0;
    set<pair<int,int>> q;
    q.insert({0,s});
    while(!q.empty())
    {
        int d=q.begin()->first;
        int u=q.begin()->second;
        q.erase(q.begin());
        for(auto v:adj_lis[u])
        {
           int des=v.first;
           int wgt=v.second;
            if(dis[des]>(dis[u]+wgt)){
                if(dis[des]!=INT_MAX)
                q.erase(q.find({dis[des],des}));
                dis[des]=dis[u]+wgt;
                q.insert({dis[des],des});
            }
            
        }
    }
    return dis;
}

int main()
{
    int n,e,i,u,v,w;
    // cout<<"No. of nodes and edges: ";
    // cin>>n>>e;
    Graph g(9);
    // while(e--)
    // {
    //     cout<<"Source and destination with weight: ";
    //     cin>>u>>v>>w;
    //     g.add_edge(u,v,w);
    // }
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    g.bfs(0);
    vector<int> ans=g.dijikstra_algo(0);
    cout<<"Shortest distance from node 0 to remaning node: ";
    for(int i=0;i<9;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}