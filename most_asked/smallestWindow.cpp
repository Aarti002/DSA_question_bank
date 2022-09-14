#include<stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    n=s1.length();
    unordered_map<char,int> mp1;
    for(i=0;i<s2.length();i++)
    mp1[s2[i]]++;
    int cnt=mp1.size();
    int m=s2.length(),s,ans=n;
    i=0;j=0;
    while(j<n)
    {
        if(mp1.find(s1[j])!=mp1.end())
        {
            mp1[s1[j]]--;
            if(mp1[s1[j]]==0)
            cnt--;
        }
        while(cnt==0)
        {
            if(ans>(j-i+1))
            {
                ans=j-i+1;
                s=i;
            }
            if(mp1.find(s1[i])!=mp1.end())
            {
                mp1[s1[i]]++;
                if(mp1[s1[i]]==1)
                cnt++;
            }
            i++;
        }
        j++;
    }
    if(cnt==n)
    cout<<-1<<endl;
    else
    cout<<s1.substr(s,ans)<<endl;
    return 0;
}