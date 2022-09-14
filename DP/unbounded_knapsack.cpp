#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int UNbounded_knapsack(vector<int> &w,vector<int> &p,int n,int W)
{
    vector<vector<int> > dp(n+1,vector<int>(W+1));
    for(int i=0;i<=n;i++) 
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(w[i-1]<=j)
            dp[i][j]=max(dp[i-1][j],dp[i][j-w[i-1]]+p[i-1]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n),w(n);
    for(i=0;i<n;i++)
    cin>>w[i];
    for(i=0;i<n;i++)
    cin>>v[i];
    int W;
    cin>>W;
    int ans=UNbounded_knapsack(w,v,n,W);
    cout<<"Maximum for unbounded knapsack:"<<ans<<endl;
    return 0;
}