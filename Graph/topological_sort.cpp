#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<int> *adj_lis;
    public:
        Graph(int v);
        void add_edge(int s,int d);
        void dfs(int s);
        void topological_sort();
};

Graph::Graph(int v) 
{
    this->v=v;
    adj_lis=new vector<int> [v];
}
//directed graph
void Graph::add_edge(int s,int d)
{
    adj_lis[s].push_back(d);
}

void Graph::dfs(int s)
{
    vector<int> vis(v,0);
    cout<<s<<" ";
    vis[s-1]=1;
    vector<int>::iterator it;
    for(it=adj_lis[s].begin();it!=adj_lis[s].end();it++)
    {
        if(vis[*it]==0)
        {
            dfs(*it);
        }
    }
}

void Graph::topological_sort()
{
    vector<int> in_deg(v,0);
    for(int i=0;i<v;i++)
    {
        vector<int> ::iterator it;
        for(it=adj_lis[i].begin();it!=adj_lis[i].end();it++)
        {
            in_deg[*it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(in_deg[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int p=q.front();
        char c=p+'A';
        cout<<c<<" ";
        q.pop();
        vector<int> ::iterator it;
        for(it=adj_lis[p].begin();it!=adj_lis[p].end();it++)
        {
            in_deg[*it]--;
            if(in_deg[*it]==0)
            q.push(*it);
        }
    }

}

int main()
{
    int n,i;
    n=9;
    Graph g(n);
    g.add_edge('A'-'A','C'-'A');
    g.add_edge('A'-'A','D'-'A');
    g.add_edge('B'-'A','D'-'A');
    g.add_edge('B'-'A','E'-'A');
    g.add_edge('D'-'A','F'-'A');
    g.add_edge('D'-'A','G'-'A');
    g.add_edge('G'-'A','I'-'A');
    g.add_edge('H'-'A','I'-'A');
    cout<<"DFS: ";
    g.dfs('B'-'A');
    cout<<endl;
    cout<<"Topological sort: ";
    g.topological_sort();
    cout<<endl;
    return 0;

}