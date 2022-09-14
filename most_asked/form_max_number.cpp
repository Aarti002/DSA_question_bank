#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    vector<string> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    map<int,vector<string> ,greater<int>> mp;
    for(i=0;i<n;i++)
    {
        mp[v[i][0]-'0'].push_back(v[i]);
    }
    map<int,vector<string> > ::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" ->";
        vector<string> temp=it->second;
        sort(temp.begin(),temp.end());
        
        for(i=temp.size()-1;i>=0;i--)
        cout<<temp[i]<<" ";
        cout<<endl;
    }
return 0;

}