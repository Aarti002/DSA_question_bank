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
        int numberOfIslands(vector<vector<int> > &a,int n,int m);
        void dfs(vector<vector<int> > &a,vector<vector<int> > &vis,int i,int j);
};

Graph::Graph(int v){
    this->v=v;
    adjlis=new vector<int>[v];
}

void Graph::dfs(vector<vector<int> > &a,vector<vector<int> > &vis,int i,int j)
{
    if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || a[i][j]==1 || vis[i][j])
    return ;
    vis[i][j]=1;
    dfs(a,vis,i+1,j);
    dfs(a,vis,i,j+1);
    dfs(a,vis,i,j-1);
    dfs(a,vis,i-1,j);

}

int Graph::numberOfIslands(vector<vector<int> > &a,int n,int m)
{
    int i,j,cnt=0;
    vector<vector<int> > vis(n,vector<int> (m,0));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==0 && !vis[i][j])
            {
                dfs(a,vis,i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int n,i,m,j;
    cin>>n>>m;
    vector<vector<int> > area(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>area[i][j];
    }
    Graph g(n*m);

    int ans=g.numberOfIslands(area,n,m);
    cout<<"Number of islands:"<<ans<<endl;
    return 0;
}