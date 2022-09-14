#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    vector<int> *adj_lis;

public:
    Graph(int v);
    void add_edge(int s, int d);
    void dfs(vector<int> &vis, int s);
    void bfs(vector<int> &vis, int s);
}; 

Graph::Graph(int n)
{
    this->v = n + 1;
    adj_lis = new vector<int>[n + 1];
}

// undirected graph

void Graph::add_edge(int u, int v)
{
    adj_lis[u].push_back(v);
    adj_lis[v].push_back(u);
}

void Graph::dfs(vector<int> &vis, int s)
{
    int i;
    vis[s] = 1;
    cout << s << " ";
    vector<int>::iterator it;
    for (it = adj_lis[s].begin(); it != adj_lis[s].end(); it++)
    {
        if (!vis[*it])
        {
            dfs(vis, *it);
        }
    }
    return;
}

void Graph::bfs(vector<int> &vis, int s)
{
    list<int> q;
    q.push_back(s);
    while (!q.empty())
    {
        int curr = q.front();
        cout << curr << " ";
        q.pop_front();
        for (auto x:adj_lis[curr])
        {
            if (!vis[x])
            {
                q.push_back(x);
                vis[x] = 1;
            }
        }
    }
    return;
}

int main()
{
    int n, e, u, v;
    cout << "No. of nodes and edges: ";
    cin >> n >> e;
    Graph g(n);
    while (e--)
    {
        cout << "Source and destination: ";
        cin >> u >> v;
        g.add_edge(u, v);
    }
    vector<int> vis(v, 0);
    cout << "DFS:" << endl;
    g.dfs(vis, 1);
    cout << "\nBFS:" << endl;
    vector<int> vis1(v, 0);
    g.bfs(vis1, 0);
    return 0;
}