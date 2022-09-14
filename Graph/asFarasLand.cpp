#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &mat,int n,int m,int x,int y,int dist=1)
{
    if(x<0 || x>=n || y<0 || y>=m || (mat[x][y]!=0 && mat[x][y]<=dist))
    return ;
    
    mat[x][y]=dist;
    dist++;
    dfs(mat,n,m,x+1,y,dist);
    dfs(mat,n,m,x-1,y,dist);
    dfs(mat,n,m,x,y+1,dist);
    dfs(mat,n,m,x,y-1,dist);

}

void bfs(vector<vector<int> > &adj,int n,int m,queue<pair<int,int> > &q,vector<vector<int> > &vis)
{
    vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0}};
    //queue<pair<int,int> > q;
    //q.push({i,j});
    int dist=0;
    while(!q.empty()){
        int sz=q.size();
        dist++;
        while(sz--){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            
            for(auto p:dir){
                int dx=x+p.first;
                int dy=y+p.second;
                if(dx<0 || dx>=n || dy<0 || dy>=m || vis[dx][dy] || adj[dx][dy]==0)
                continue;
                adj[dx][dy]=adj[x][y]+1;
                vis[dx][dy]=1;
                q.push({dx,dy});
            }
        }
        
    }
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int ans=-1;
    vector<vector<int> > mat(n,vector<int>(m));
    vector<vector<int> > vis(n,vector<int>(m,0));
    queue<pair<int,int> > q;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>mat[i][j];
    }
  //  queue<pair<int,int> > q;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(mat[i][j]==1 )
            {
                mat[i][j]=0;
                
                q.push({i,j});
                //bfs(mat,n,m,i,j,vis);
                
            }
            else
            mat[i][j]=1;
        }
    }
    bfs(mat,n,m,q,vis);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //if(mat[i][j]>1)
           // ans=max(ans,mat[i][j]-1);
           cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
 //   cout<<ans<<endl;
    return 0;

}