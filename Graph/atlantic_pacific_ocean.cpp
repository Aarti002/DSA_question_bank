#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int> > &mat,vector<vector<int> > &vis,int n,int m,queue<pair<int,pair<int,int> > > &q)
{
    vector<vector<int> > dir={{0,1},{0,-1},{1,0},{-1,0}};
    int i;
    while(!q.empty())
    {
        
            int h=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            for(i=0;i<4;i++)
            {
                int dx=x+dir[i][0];
                int dy=y+dir[i][1];
                if(dx<0 || dx>=n || dy<0 || dy>=m || h>mat[dx][dy] || vis[dx][dy])
                continue;
                vis[dx][dy]=1;
                q.push({mat[dx][dy],{dx,dy}});
            }
    }
    
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > visP(n,vector<int>(m,0));
    vector<vector<int> > visA(n,vector<int>(m,0));
    vector<vector<int> > mat(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>mat[i][j];
    }
    queue<pair<int,pair<int,int> > > pac,atl;
    for(i=0;i<m;i++)
    {
        pac.push({mat[0][i],{0,i} });
        atl.push({mat[n-1][i],{n-1,i}});
        visP[0][i]=1;
        visA[n-1][i]=1;
    }
    for(i=1;i<n;i++)
    {
        pac.push({mat[i][0],{i,0}});
        atl.push({mat[i][m-1],{i,m-1}});
        visP[i][0]=1;
        visA[i][m-1]=1;
    }
    bfs(mat,visP,n,m,pac);
    bfs(mat,visA,n,m,atl);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(visP[i][j] && visA[i][j])
            cout<<"["<<i<<", "<<j<<"], ";
        }
    }
    cout<<endl;
    return 0;
}