#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int min_cost(vector<vector<int> > &v,int n,int m)
{
    if(0>n || 0>m)
    return INT_MAX;
    if(n==0 && m==0)
    return v[n][m];
    else
    return v[n][m]+min(min_cost(v,n,m-1),min(min_cost(v,n-1,m),min_cost(v,n-1,m-1)));

    
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > cost(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>cost[i][j];
    }
    int ans=min_cost(cost,n-1,m-1);
    cout<<ans<<endl;
    return 0;
}