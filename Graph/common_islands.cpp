#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &g1,vector<vector<int> > &g2,int i,int j,int n,int m,int &flag)
{
    if(i<0 || i>=n || j<0 || j>=m || g2[i][j]==0)
    return ;
    if(g1[i][j]==0)
    flag=0;
    g2[i][j]=0;
    dfs(g1,g2,i+1,j,n,m,flag);
    dfs(g1,g2,i-1,j,n,m,flag);
    dfs(g1,g2,i,j+1,n,m,flag);
    dfs(g1,g2,i,j-1,n,m,flag);
}

int common_islands(vector<vector<int> > &g1,vector<vector<int> > &g2,int n,int m)
{
    int i,j,cnt=0;
    vector<vector<int> > vis(n,vector<int>(m,0));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(g2[i][j])
            {
                int flag=1;
                dfs(g1,g2,i,j,n,m,flag);
                if(flag==1)
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
    vector<vector<int> > g1(n,vector<int>(m)),g2(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>g1[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>g2[i][j];
        }
    }
    int ans=common_islands(g1,g2,n,m);
    cout<<ans<<endl;
    return 0;

}