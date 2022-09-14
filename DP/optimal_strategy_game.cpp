#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,i,j;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    vector<vector<long long int> > dp(n,vector<long long int>(n,-1));
    for(int l=0;l<n;l++){
        for(i=0,j=l;j<n;j++,i++){
            if(l==0)
            dp[i][j]=v[i];
            else if(l==1)
            dp[i][j]=max(v[i],v[j]);
            else{
                long long int v1=v[i]+min(dp[i+1][j-1],dp[i+2][j]);
                long long int v2=v[j]+min(dp[i-1][j-1],dp[i][j-2]);
                dp[i][j]=max(v1,v2);
            }
            
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}