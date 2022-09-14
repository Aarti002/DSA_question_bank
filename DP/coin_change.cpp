#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int all_possible_changes(vector<int> &v,int n,int tc)
{
    vector<vector<int> > dp(n+1,vector<int>(tc+1));
    int i,j;
    for(i=0;i<=n;i++)
    dp[i][0]=1;
    for(i=0;i<=tc;i++)
    dp[0][i]=0;
    //like unbounded knapsack
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=tc;j++)
        {
            if(v[i-1]<=j)
            dp[i][j]=dp[i][j-v[i-1]]+dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][tc];
}

int main()
{
    int n,i,tc;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    cin>>tc;
    int ans=all_possible_changes(v,n,tc);
    cout<<ans<<endl;
    return 0;
}