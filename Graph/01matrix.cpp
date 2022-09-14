#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int> > &g,vector<vector<int> > &vis,int n,int m,int x,int y)
{
    if(x>=n || x<0 || y>=m || y<0 || vis[x][y]==1)
    return -1;
   if(vis[x][y]==0)
   return 0;
    vis[x][y]=1;
    int res= 1+min(dfs(g,vis,n,m,x+1,y),min(dfs(g,vis,n,m,x,y+1),min(dfs(g,vis,n,m,x-1,y),dfs(g,vis,n,m,x,y-1))));
    vis[x][y]=0;
    return res;
}

void bfs(vector<vector<int> > &g,int n,int m,queue<pair<int,int> > &q,vector<vector<int> > &vis)
{
    int i,j,move=0;
    vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0}};
    while(!q.empty())
    {
            pair<int,int> p=q.front();
            q.pop();
            for(i=0;i<4;i++)
            {
                int x=p.first+dir[i].first;
                int y=p.second+dir[i].second;
                if((x<n && x>=0 && y<m && y>=0 )&& vis[x][y]==-1)
               {
                vis[x][y]=vis[p.first][p.second]+1;
                q.push({x,y});
               }
               // g[x][y]=0;
            }
        
        move++;
    }
    return ;
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > mat(n,vector<int>(m));
    vector<vector<int> > vis(n,vector<int>(m,-1));
    queue<pair<int,int> > q;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                q.push({i,j});
                vis[i][j]=0;
            }
        }
    }
    bfs(mat,n,m,q,vis);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cout<<vis[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}