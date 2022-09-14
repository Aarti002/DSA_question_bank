#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int max_rod_cutting(vector<int> &v,int n,int k)
{
    int i,j,dp[n+1][k+1];
    for(i=0;i<=n;i++)
    dp[0][i]=0;
    for(i=0;i<=k;i++)
    dp[i][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(j>=v[i-1])
            dp[i][j]=max(dp[i-1][j]+v[i-1],dp[i-1][j-1]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][k];
}

int max_profit(vector<int> &v,int n)
{
    vector<vector<int> > dp(n+1,vector<int>(n+1,0));
    int i,j;
    vector<int> pos(n);
    for(i=0;i<n;i++)
    pos[i]=i+1;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(pos[i-1]<=j)
            dp[i][j]=max(dp[i][j-pos[i-1]]+v[i-1],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][n];
}

int main()
{
    int n,k,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    cin>>k;
    int ans=max_rod_cutting(v,n,k);
    cout<<max_profit(v,n)<<endl;
    cout<<ans<<endl;
    return 0;
}