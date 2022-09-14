#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int> > &v,int i,int j,int n,int m)
{
    if(i<0 || i>=n || j<0 || j>=m)
    return false;
    if(v[i][j]==1)
    return true;
    v[i][j]=1;
    bool down=dfs(v,i+1,j,n,m);
    bool right=dfs(v,i,j+1,n,m);
    bool up=dfs(v,i-1,j,n,m);
    bool left=dfs(v,i,j-1,n,m);
    return up && down && left && right;
    
}

int countIslands(vector<vector<int> > &v,int n,int m)
{
    int i,j;
    int cnt=0;
    vector<vector<int> > vis(n,vector<int>(m,0));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(v[i][j]==0)
            {
                
                if(dfs(v,i,j,n,m))
               cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    int ans=countIslands(v,n,m);
    cout<<ans<<endl;
    return 0;
}