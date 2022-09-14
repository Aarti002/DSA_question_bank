#include<stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    string s,p;
    cin>>s;
    cin>>p;
    vector<int> ans;
    sort(p.begin(),p.end());
    for(i=0;i<s.length();i++)
    {
        string t=s.substr(i,p.length());
        sort(t.begin(),t.end());
        if(t==p)
        ans.push_back(i);
    }
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0; 

}