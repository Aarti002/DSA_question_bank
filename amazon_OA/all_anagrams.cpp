#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    string s,p;
    cin>>s>>p;
    vector<int> vs(26,0),vp(26,0);
    for(i=0;i<p.length();i++)
    {
        vs[s[i]-'a']++;
        vp[p[i]-'a']++;
    }
    int r=0,l=p.length();
    vector<int> ans;
    while(r<s.length())
    {
        if(vs==vp)
        {
            ans.push_back(r);
        }
        vs[s[r]-'a']--;
        vs[s[l]-'a']++;
        r++;
        l++;
    }
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}