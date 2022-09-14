#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    string s;
    cin>>s;
    n=s.length();
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(i=2;i<=n;i++)
    {
        dp[i]=0;
        if(s[i-1]>'0')
        dp[i]=dp[i-1];
        if((s[i-2]=='1' || s[i-2]=='2') && s[i-1]<='7') 
        dp[i]+=dp[i-2];
    }
    cout<<dp[n]<<endl;
    return 0;
}