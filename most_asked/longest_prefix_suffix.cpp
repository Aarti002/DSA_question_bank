#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v1,vector<int> &v2)
{
    int i;
    for(i=0;i<26;i++)
    cout<<v1[i]<<" ";
    cout<<endl;
    for(i=0;i<26;i++)
    cout<<v2[i]<<" ";
    cout<<endl;
}

int main()
{
    int n,i,j;
    string s;
    cin>>s;
    vector<int> vs(26,0);
    vector<int> ve(26,0);
    n=s.length();
    i=n-1;j=1;
    int ans=-1;
    while(i>0 && j<n-1)
    {
        if(s[i]!=s[j])
        {
            i--;
            j++;
            continue;
        }
        string s1=s.substr(0,j);
        string s2=s.substr(i,n);
        if(s1==s2)
        {
            ans=s1.length();
            break;
        }
        i--;
        j++;
    }
    if(ans!=-1)
    cout<<ans<<endl;
    else if(s[0]==s[n-1])
    cout<<1<<endl;
    else
    cout<<0<<endl;
    
    return 0;
}