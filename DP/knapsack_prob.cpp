#include<stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int max_profit_kp(vector<int> &wgt,vector<int> &pro,int n,int w)
{
    vector<vector<int> > dp(n+1,vector<int> (w+1,0));
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0; 
            else if(wgt[i-1]<=j)
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-wgt[i-1]]+pro[i-1]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}

int main()
{
    int n,i,w;
    cin>>n;
    vector<int> wgt(n),pro(n);
    cin>>w;
    for(i=0;i<n;i++)
    cin>>wgt[i];
    for(i=0;i<n;i++)
    cin>>pro[i];
    int ans=max_profit_kp(wgt,pro,n,w);
    cout<<"Maximum profit for bounded kanpsack: "<<ans<<endl;
    return 0;
}