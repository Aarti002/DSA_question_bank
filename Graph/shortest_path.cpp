#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int> > &mat,int sx,int sy,int x,int y)
{
    if(sx<0 || sy<0 || sx>=mat.size() || sy>=mat[0].size() || mat[sx][sy]==0)
    return 0;
    mat[sx][sy]=0;
    return 1+min(dfs(mat,sx+1,sy,x,y),min(dfs(mat,sx-1,sy,x,y),min(dfs(mat,sx,sy+1,x,y),dfs(mat,sx,sy-1,x,y))));
}

int bfs(vector<vector<int> > &mat,int x,int y)
{
    queue<pair<pair<int,int>,int> > q;
    q.push({{0,0},0});
   // int x1=0,y1=0;
    int i,n=mat.size(),m=mat[0].size();
    vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0}};
    int cnt=0;
    vector<vector<int> > vis(n,vector<int>(m,0));
    vis[0][0]=1;
    while(!q.empty())
    {
        pair<pair<int,int>,int > pnt=q.front();
        int dist=pnt.second;
        q.pop();
        if(pnt.first.first==x && pnt.first.second==y)
            return dist;
        for(i=0;i<4;i++)
        {
            int dx=pnt.first.first+dir[i].first;
            int dy=pnt.first.second+dir[i].second;
            if(dx<0 || dx>=n || dy<0 || dy>=m || mat[dx][dy]==0 || vis[dx][dy]==1)
            continue;
            vis[dx][dy]=1;
            q.push({{dx,dy},dist+1});
            //mat[dx][dy]=0;
        }
       // cnt++;
    }
    return -1;
}

int main()
{
    int n,m,i,j,x,y;
    cin>>n>>m;
    vector<vector<int> > mat(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    cin>>x>>y;
    //DFS
    int ans=bfs(mat,x,y);
    cout<<ans<<endl;
    return 0;

}