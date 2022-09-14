#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &m,int x,int y,queue<pair<int,int> > &fi)
{
    if(x<0 || x>=m.size() || y<0 || y>=m[0].size() || m[x][y]==-1 || m[x][y]==0)
    return ;
    m[x][y]=-1;
    fi.push({x,y});
    dfs(m,x+1,y,fi);
    dfs(m,x-1,y,fi);
    dfs(m,x,y+1,fi);
    dfs(m,x,y-1,fi);
    return ;
}

int bfs(vector<vector<int> > &mat,queue<pair<int,int> > &fi)
{cout<<"IN BFS\n";
    int n=mat.size(),m=mat[0].size(),i,j;
    int moves=0,ans=INT_MAX;
    vector<pair<int,int> > dir{{0,1},{0,-1},{1,0},{-1,0}};
    while(!fi.empty())
    {
        int sz=fi.size();
        while(sz--){
        pair<int,int> p=fi.front();
        fi.pop();
        for(i=0;i<4;i++)
        {
            int x=p.first+dir[i].first;
            int y=p.second+dir[i].second;
            if(x>=n || x<0 || y>=m || y<0 || mat[x][y]==-1)
            continue;
            if(mat[x][y]==1)
            return moves;
            mat[x][y]=-1;
            fi.push({x,y});
        }
        }
        moves++;
    }
    return -1;
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > mat(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>mat[i][j];
    }
    int flag=0;
    queue<pair<int,int> > fi;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(mat[i][j]==1)
            {
                dfs(mat,i,j,fi);
                flag=1;
                break;
            }
        }
        if(flag==1)
        break;
    }
    int ans=-1;
    if(flag==1)
    ans=bfs(mat,fi);
    cout<<ans<<endl;
    return 0;
}