#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isPosssible(vector<string> &v,string s,vector<int> &dp)
{
    int sz=s.length();
    if(sz==0)
        return true;
    if(dp[sz])
        return true;
    for(int p=1;p<=sz;p++)
    {
        string t=s.substr(0,p);
        string rem=s.substr(p,sz-p);
        if(find(v.begin(),v.end(),t)!=v.end() && isPosssible(v,rem,dp)){
            return dp[p]=true;
        }
    }
    return dp[sz]=false;
}

int main()
{
    int n,i;
    cin>>n;
    vector<string> vs(n);
    string s;
    for(i=0;i<n;i++)
    cin>>vs[i];
    cin>>s;
    vector<int> dp(n+1,0);
    cout<<"Is it possible to create this string: "<<isPosssible(vs,s,dp)<<endl;;
    return 0;
}