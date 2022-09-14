#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    string s;
    cin>>s;
    map<char,int> mp;
    for(i=0;i<s.length();i++)
    {
        mp[s[i]]++;
    }
    
    string ans="";
    map<char,int> ::iterator it;
    priority_queue<pair<int,char> > pq;
    for(it=mp.begin();it!=mp.end();it++)
    {
        pq.push({it->second,it->first});
    }

    while(pq.size()>1)
    {
        pair<char,int> val=pq.top();
        pq.pop();
        int n=val.first;
        char c=val.second;
        int n1=pq.top().first;
        char c1=pq.top().second;
        pq.pop();
        n1--;
        n--;
        ans+=c;
        ans+=c1;
        if(n>0)
        pq.push({n,c});
        if(n1>0)
        pq.push({n1,c1});
    }
    if(pq.size()==1)
    {
        int n1=pq.top().first;
        char c1=pq.top().second;
        if(n1==1)
        ans+=c1;
        else
        cout<<"-1"<<endl;
    }
    cout<<ans<<endl;
    return 0;
}