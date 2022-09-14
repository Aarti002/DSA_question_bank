#include <stdio.h>
#include<stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int max_inc_subseq(vector<int> &v,int n)
{
    vector<int> temp=v;
    int i,j;
    sort(temp.begin(),temp.end());
    vector<vector<int> > dp(n+1,vector<int>(n+1,0));
    
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(temp[j-1]==v[i-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main()
{
    int n,i,k;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int inc_l=max_inc_subseq(v,n);
    cout<<inc_l<<endl;
    return 0;
}