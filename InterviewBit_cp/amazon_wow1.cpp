#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    string s,temp;
    cin>>s;
    char mx='a';
    temp=s;
    sort(temp.begin(),temp.end());
    cout<<temp<<endl;
    int mnp=0;
    string ans="";
    while(!s.empty())
    {   char mn='z';
        for(i=0;i<s.length();i++)
        {
            if(s[i]<mn)
            {
                mn=s[i];
                mnp=i;
            }
        }
        if(mnp==s.length()-1)
        {
            reverse(s.begin(),s.end());
            ans+=s;
            break;
        }
        else{
            ans+=mn;
            s.erase(s.begin()+mnp);
        }
    }
    cout<<ans<<endl;
    return 0;
}