#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &v,int n,int sum)
{
    vector<vector<int> > dp(n+1,vector<int>(sum+1));
    int i,j;
    for(i=0;i<=n;i++)
    dp[i][0]=1;
    for(i=1;i<=sum;i++)
    dp[0][i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(v[i-1]<=j)
            dp[i][j]=dp[i-1][j-v[i-1]]||dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int n,i,ss;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    cin>>ss;
    cout<<"Is it possible to get sum:"<<isPossible(v,n,ss);
    return 0;
}