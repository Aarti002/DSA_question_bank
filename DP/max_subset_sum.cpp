#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int max_subset_sum(vector<int> &v,int n)
{
    int i,j;
    int dp[n+1]={0};
    for(i=1;i<=n;i++){
        
    dp[i]=max(dp[i-1]+v[i-1],dp[i-1]);
    }
    return dp[n];
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int mx_sum=max_subset_sum(v,n);
    cout<<mx_sum<<endl;
    return 0;
}