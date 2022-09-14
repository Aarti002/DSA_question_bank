#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(i=3;i<=n;i++)
    {
        for(j=0;j<=i;j++)
        {
            dp[i]=dp[i]+dp[j]*dp[i-j-1];
        }
    }
    for(i=0;i<=n;i++)
    cout<<dp[i]<<" ";
    return 0;
}