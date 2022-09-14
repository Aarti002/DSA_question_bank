#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    string s;
    cin>>s;
    n=s.length();
    map<char,int> mp;
    for(i=0;i<n;i++)
    {
        mp[s[i]-'a']++;
        if(mp[s[i]-'a']>1)
        {
            int l=i-ss;
            if(l>pl)
            {
                pl=l;
                
            }
        }
    }

}