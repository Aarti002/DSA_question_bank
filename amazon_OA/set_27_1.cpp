#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,k;
    cin>>n>>k;
    vector<string> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    map<string,int> mp;
    for(i=0;i<n;i++)
    {
        mp[v[i]]++;
    }
    sort(mp.begin(),mp.end());
    map<string,int> ::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    cout<<it->first<<" "<<it->second<<endl;
    return 0;
}