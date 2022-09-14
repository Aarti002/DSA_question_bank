#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,i,t,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<pair<int,int> > v;
        string s;
        map<string,int> mp;
        multimap<int,string> mpp;
        for(i=0;i<3*n;i++)
        {
            cin>>s>>x;
            mp[s]+=x;
        }
        multimap<string,int> ::iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        mpp.insert({it->second,it->first});
        map<int,string> ::iterator itt;
        for(itt=mpp.begin();itt!=mpp.end();itt++)
        cout<<itt->first<<" ";
        cout<<endl;

    }
    return 0;
}