#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int numberOfLIS(vector<int> &v,int n)
{
    int i,j;
    vector<int> dp(n,1),cnt(n,1);
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(v[i]>v[j] && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                cnt[i]=cnt[j];
            }
            else if(v[i]>v[j] && dp[i]==dp[j]+1)
            cnt[i]+=cnt[j]; 
        }
    }
    int mx=*max_element(dp.begin(),dp.end());
        int a=0;
        cout<<mx<<endl;
        for(i=0;i<n;i++)
        {
            if(dp[i]==mx)
                a+=cnt[i];
        }
    for(i=0;i<n;i++)
    cout<<dp[i]<<" ";
    cout<<endl;
    for(i=0;i<n;i++)
    cout<<cnt[i]<<" ";
    cout<<endl;
    return a;
}

int main()
{
    int i,j,n;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int ans=numberOfLIS(v,n);
    cout<<"Number of LIS:"<<ans<<endl;
    return 0;
}