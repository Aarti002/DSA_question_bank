#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int unique_paths(vector<vector<int> > &v,int n,int m,int i,int j)
{
    if(i>=n || j>=m || v[i][j]==1)
    return 0;
    v[i][j]=1;
    if(i==n-1 && j==m-1)
    return 1;
    return 1+unique_paths(v,n,m,i+1,j)+unique_paths(v,n,m,i,j+1);
}

int main()
{
    int n,i,j,m;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>v[i][j];
    }
    int ans=unique_paths(v,n,m,0,0);
    cout<<ans<<endl;
    return 0;
}