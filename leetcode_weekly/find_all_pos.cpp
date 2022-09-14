#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    string s,p;
    cin>>s;
    cin>>p;
    vector<int> v;
    int l=p.length();
    for(i=0;i<=s.length()-l;i++)
    {
        string temp=s.substr(i,l);
        if(temp==p)
        v.push_back(i);

    }
    for(i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    return 0;
}