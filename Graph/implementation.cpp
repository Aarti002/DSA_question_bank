#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct graph
{
    int v;
    int e;
    vector<vector<int>> adjl;
};

void createGraph(struct graph *start, int n, int m)
{
    start->v = n;
    start->e = m;
    start->adjl.resize(n + 1);
    cout << "Enter source and destination node: ";
    int s, d;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> d;
        start->adjl[s].push_back(d);
        start->adjl[d].push_back(s);
    }
    return;
}

void displayGraph(struct graph *g)
{
    int e = g->e;
    for (int i = 0; i <= g->v; i++)
    {
        cout << "For node " << i << " :";
        for (auto it : g->adjl[i])
            cout << it << " ";
        cout << endl;
    }
    return;
}

int main()
{
    int n, m;
    cout << "Enter number of vertex: ";
    cin >> n;
    cout << "\nEnter number of edges: ";
    cin >> m;
    struct graph *g;
    createGraph(g, n, m);
    displayGraph(g);
    return 0;
}