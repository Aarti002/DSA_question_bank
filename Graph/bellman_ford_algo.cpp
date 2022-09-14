#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int s, d, w;
};

struct Graph
{
    int v, e;
    struct edge *egd;
};

struct Graph *createGraph(int v, int e)
{
    struct Graph *newG = new Graph;
    newG->e = e;
    newG->v = v;
    newG->egd = new edge[e];
    return newG;
}

vector<int> bellmanfords_algo(Graph *g, int src)
{
    vector<int> dist(g->v);
    int i, j;
    for (i = 0; i < g->v; i++)
        dist[i] = INT_MAX; 
    dist[src] = 0;

    for (i = 1; i < g->v; i++)
    {
        for (j = 0; j < g->e; j++)
        {
            int x = g->egd[j].s;
            int y = g->egd[j].d;
            int wgt = g->egd[j].w;
            // cout<<s<<" "<<d<<" "<<w<<endl;
            dist[y] = min(dist[y], dist[x] + wgt);
        }
    }

    return dist;
}

int main()
{
    int e, n, i, w;
    char x, y, src;
    cout << "Enter number of nodes and edegs respectively: ";
    cin >> n >> e;
    struct Graph *g;
    g = createGraph(n, e);
    cout << "Provide source and destination : ";

    for (i = 0; i < e; i++)
    {
        cin >> x >> y >> w;
        g->egd[i].s = x - 'a';
        g->egd[i].d = y - 'a';
        g->egd[i].w = w;
    }
    cout << "Enter source node: ";
    cin >> src;
    vector<int> ans = bellmanfords_algo(g, src - 'a');
    cout << "Shortest distance from source node " << src << " to remaining node in graph is: ";
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}