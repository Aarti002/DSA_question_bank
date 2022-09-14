#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int> > &v,int i,int j,int n,int m)
{
    if(i<0 || i>=n || j<0 || j>=m || v[i][j]==0)
    return 0;
    v[i][j]=0;
    return 1+dfs(v,i+1,j,n,m)+dfs(v,i-1,j,n,m)+dfs(v,i,j+1,n,m)+dfs(v,i,j-1,n,m);

}

int countEncalves(vector<vector<int> > &v,int n,int m)
{
    int i,j;
    vector<vector<int> > vis(n,vector<int>(m,0));
    int boundary_island=0,all_one=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        all_one+=v[i][j];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if((i==0 || i==n-1) || (j==0 || j==m-1) && v[i][j]==1)
            {
                boundary_island+=dfs(v,i,j,n,m);
            }
        }
    }
    return all_one-boundary_island;
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int> (m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }

    int ans=countEncalves(v,n,m);
    cout<<ans<<endl;
    return 0;
}