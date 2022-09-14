#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    string s;
    cin>>s;
    string ans="",unq="";
    //ans+=s[0];
    map<char,int> mp;
    deque<char> q;
    int ind=-1;
    for(i=0;i<s.length();i++)
    {
        mp[s[i]-'a']++;
        if(mp[s[i]-'a']>1)
        {
            while(!q.empty() && mp[q.front()-'a']>1)
            q.pop_back();
            if(q.empty())
            s[i]='#';
            else
            s[i]=q.front();
        }
        else{
            q.push_back(s[i]);
            s[i]=q.front();
        }
        
    }
    
    cout<<s<<endl;
    return 0;
}