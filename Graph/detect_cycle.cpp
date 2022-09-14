#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	vector<int> *adj;

public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isCyclicUtil(int v, vector<int> &vis, int parent);
	bool isCyclic();
	void displayGraph();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

bool Graph::isCyclicUtil(int v, vector<int> &vis, int parent)
{
	vis[v] = 1;
	vector<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if (!vis[*i])
		{
			if (isCyclicUtil(*i, vis, v))
				return true;
		}
		else if (*i != parent)
			return true;
	}
	return false;
}

bool Graph::isCyclic()
{
	vector<int> vis(V, 0);

	for (int u = 0; u < V; u++)
	{
		if (!vis[u])
		{
			if (isCyclicUtil(u, vis, -1))
				return true;
		}
	}
	return false;
}

void Graph::displayGraph()
{
	for (int i = 0; i < V; i++)
	{
		cout << "Node " << i << ": ";
		for (auto it : adj[i])
			cout << it << " ";
		cout << endl;
	}
}

int main()
{
	int n, e;
	cout << "Enter no. of vertex: ";
	cin >> n;
	Graph g1(n);
	cout << "\nEnter no. of edges: ";
	cin >> e;
	while (e--)
	{
		int s, d;
		cin >> s >> d;
		g1.addEdge(s, d);
	}
	g1.displayGraph();
	g1.isCyclic() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";
	return 0;
}
