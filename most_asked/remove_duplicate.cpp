#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<char> v(26,0);
    string ans="";
    for(int i=0;i<s.length();i++)
    {
        if(v[s[i]-'a']==0)
        {
            ans+=s[i];
            v[s[i]-'a']=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}