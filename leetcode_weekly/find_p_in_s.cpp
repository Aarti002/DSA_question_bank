#include <stdio.h>
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
    int cnt=0;
    int l=p.length();
    for(i=0;i<=s.length()-l;i++)
    {
        string t=s.substr(i,l);
        if(t==p)
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}