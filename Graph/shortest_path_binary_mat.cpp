#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*
int minPathLen(vector<vector<int> > &v,int i,int j,int n,int m,vector<vector<int> > &vis,int cnt)
{
    vis[i][j]=1;
    if(i==n-1 && j==m-1)
    return cnt;
    if((i+1)<=(n-1) && j<=(m-1) && v[i+1][j]!=1 && vis[i+1][j]==0)
    int d=minPathLen(v,i+1,j,n,m,vis,cnt+1);
    if((i)<=(n-1) && (j+1)<=(m-1) && v[i][j+1]!=1 && vis[i][j+1]==0)
    int r=minPathLen(v,i,j+1,n,m,vis,cnt+1);
    if((i+1)<=(n-1) && (j+1)<=(m-1) && v[i+1][j+1]!=1 && vis[i+1][j+1]==0)
    int dg=minPathLen(v,i+1,j+1,n,m,vis,cnt+1);
    if((i-1)>=0 && (j)<=(m-1) && v[i-1][j]!=1 && vis[i-1][j]==0)
    int l=minPathLen(v,i-1,j,n,m,vis,cnt+1);
    if((i+1)<=(n-1) && (j-1)>=0 && v[i+1][j-1]!=1 && vis[i+1][j-1]==0)
    int r=minPathLen(v,i+1,j-1,n,m,vis,cnt+1);
    if((i-1)>=0 && (j)<=(m-1) && v[i-1][j]!=1 && vis[i-1][j]==0)
    int r=minPathLen(v,i-1,j,n,m,vis,cnt+1);
    if((i-1)>=0 && (j-1)>=0 && v[i-1][j-1]!=1 && vis[i-1][j-1]==0)
    int r=minPathLen(v,i-1,j-1,n,m,vis,cnt+1);
    if((i-1)>=0 && (j+1)<=(m-1) && v[i-1][j+1]!=1 && vis[i-1][j+1]==0)
    int r=minPathLen(v,i-1,j+1,n,m,vis,cnt+1);
    return min()
}*/

int minPathLen(vector<vector<int> > &v,int n,int m,vector<vector<int> > &vis)
{
    queue<pair<pair<int,int>, int> > q;
    q.push(make_pair(make_pair(0,0),1));
    int x=0,y=0;
    vis[0][0]=1;
    if(v[0][0]==1)
    return -1;
    if(vis[0][0] && n==1 && m==1)
    return 1;
    while(!q.empty())
    {
        pair<int,int> p=q.front().first;
        int nx=p.first;
        int ny=p.second;
        int l=q.front().second;
        q.pop();
        vector<pair<int,int>> neighbour ={{0,1},{0,-1},{-1,-1},{1,1},{1,0},{-1,1},{-1,-1},{1,-1}};
        for(pair<int,int> ngh:neighbour)
        {
            int tx=nx+ngh.first;
            int ty=ny+ngh.second;
            if(tx>=0 && ty>=0 && tx<n && ty<m && vis[tx][ty]==0 && v[tx][ty]==0)
            {
                vis[tx][ty]=1;
                q.push(make_pair(make_pair(tx,ty),l+1));
                if(tx==n-1 && ty==m-1)
                return l;
            }
        }
        
    }
    return -1;
}


int main()
{
    int n,m,j,i;
    cin>>n>>m;
    vector<vector<int> > mat(n,vector<int> (m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>mat[i][j];
    }
    vector<vector<int> > vis(n,vector<int>(m,0));
    int ans=minPathLen(mat,n,m,vis);
    cout<<ans<<endl;
    return 0;
}