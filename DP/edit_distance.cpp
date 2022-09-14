#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int edit_distance(string s1,string s2,int n,int m)
{
    if(n==0)
        return 0;
    if(m==0)
        return 0;
    if(s1[n-1]==s2[m-1])
        return edit_distance(s1,s2,n-1,m-1);
    return 1+min(edit_distance(s1,s2,n-1,m),min(edit_distance(s1,s2,n,m-1),edit_distance(s1,s2,n-1,m-1)));

}
int dp[1000][1000];

int edit_dist_tablulation(string s1,string s2,int n,int m)
{
    if(n==0)
    return m;
    if(m==0)
    return n;
    if(dp[n][m]!=-1)
    return dp[n][m];
    if(s1[n-1]==s2[m-1])
    {
        if(dp[n-1][m-1]!=-1)
        return dp[n][m]=dp[n-1][m-1];
        else
        return dp[n][m]=edit_dist_tablulation(s1,s2,n-1,m-1);
    }
    else{
        int m1,m2,m3;
        if(dp[n-1][m]!=-1)
        m1=dp[n-1][m];
        else
        m1=edit_dist_tablulation(s1,s2,n-1,m);
        if(dp[n][m-1]!=-1)
        m2=dp[n][m-1];
        else
        m2=edit_dist_tablulation(s1,s2,n,m-1);
        if(dp[n-1][m-1]!=-1)
        m3=dp[n-1][m-1];
        else
        m3=edit_dist_tablulation(s1,s2,n-1,m-1);
        return dp[n][m]=min(m1,min(m2,m3))+1;


    }
}

int main()
{
    int n,i,m;
    
    string s1,s2;
    cin>>s1>>s2;
    memset(dp,-1,sizeof(dp));
    n=s1.length();m=s2.length();
    int dis=edit_distance(s1,s2,n,m);
    cout<<dis<<endl;
    return 0;
}