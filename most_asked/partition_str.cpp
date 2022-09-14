#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    string s;
    cin>>s;
    i=0;
    map<char,int> mp;
    n=s.length();
    for(j=n-1;j>=0;j--)
    {
        if(mp.find(s[j])==mp.end())
        mp[s[j]]=j;
    }
    int l=0,end=0;
    vector<int> ans;
    for(i=0;i<s.length();i++)
    {
        l++;
        end=max(end,mp[s[i]]);
        if(i==end)
        {
            ans.push_back(l);
            l=0;
        }
    }
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}