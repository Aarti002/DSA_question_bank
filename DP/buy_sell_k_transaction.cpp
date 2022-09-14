#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,i,j,prev;
    cin>>n>>k;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];

    vector<vector<int> > dp(k+1,vector<int>(n,0));
    for(i=1;i<=2;i++)
    {
        int mx=INT_MIN;
        for(j=1;j<n;j++)
        {
            int lt=dp[i-1][j-1];
            if((lt-v[j-1])>mx)
            mx=lt-v[j-1];
            if((mx+v[j])>dp[i][j-1])
            dp[i][j]=mx+v[j];
            else
            dp[i][j]=dp[i][j-1];
           
        }
    }
    cout<<dp[k][n-1]<<endl;
    return 0;

}