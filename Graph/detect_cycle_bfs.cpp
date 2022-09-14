#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<int> *adj;
    
    public:
        Graph(int v);
        void add_edge(int u,int v);
        void bfs(vector<int> &vis,int s);
        bool isCyclicUtil(int p,vector<int> &vis,int s);
        bool isCyclic();
};

Graph::Graph(int v)
{
    this->v=v;
    adj=new vector<int>[v];
}

void Graph::add_edge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::bfs(vector<int> &vis,int s)
{
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int c=q.front();
        q.pop();
        cout<<c<<" ";
        vector<int> ::iterator it;
        for(it=adj[c].begin();it!=adj[c].end();it++)
        {
            if(!vis[*it])
            {
                q.push(*it);
                vis[*it]=1;
            }
        }
    }
    return ;
}


bool Graph::isCyclicUtil(int v,vector<int> &vis, int parent)
{
    queue<int> q;
    q.push(v);
	vis[v] = 1;
    while(!q.empty())
    {
        int c=q.front();
        q.pop();
        vector<int> ::iterator it;
        for(it=adj[v].begin();it!=adj[v].end();it++)
        {
            if(!vis[*it])
            {
                q.push(*it);
                vis[*it];
            }
            else if(*it!=parent)
            return true;
        }
    }
	
	return false;
}



bool Graph::isCyclic()
{
	vector<int> vis(v,0);

	for (int u = 0; u < v; u++)
	{
		if (!vis[u])
         {   if (isCyclicUtil(u, vis, -1))
                return true;
         }
	}
	return false;
}



int main()
{
    int n,e;
    cin>>n>>e;
    Graph g(n);
    cout<<"Enter edges:";
    int u,v;
    while(e--)
    {
        cin>>u>>v;
        g.add_edge(u,v);
    }
    cout<<endl;
    vector<int> vis(n,0);
    g.bfs(vis,0);
    cout<<endl<<g.isCyclic()<<endl;
    return 0;

}