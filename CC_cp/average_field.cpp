#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int countPossibleWays(vector<int> &v,int n,int s,vector<vector<int> > &dp)
{
    if(s==0)
    return 1;
    if(n==0)
    return 0;
    if(dp[n][s]!=-1)
    return dp[n][s];
    if(v[n-1]<=s)
    return dp[n][s]=countPossibleWays(v,n,s-v[n-1],dp)+countPossibleWays(v,n-1,s,dp);
    else
    return dp[n][s]=countPossibleWays(v,n-1,s,dp);
    
    return dp[n][s];
}

int main()
{
    int n,i,s;
    cin>>n;
    vector<int> v(n);
    
    for(i=0;i<n;i++)
    cin>>v[i];
    cin>>s;
    vector<vector<int> > dp(n+1,vector<int>(s+1,-1));
    int ways=countPossibleWays(v,n,s,dp);
    cout<<ways<<endl;
    return 0;
}