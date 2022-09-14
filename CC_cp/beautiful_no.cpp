#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

long long int isBeautiful(long long int n)
{
    long long int i;
    map<char,int> mp;
    string s=to_string(n);
    for(i=0;i<s.length();i++)
    mp[s[i]]++;
    map<char,int> ::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        int x=it->first-'0';
        if(x!=it->second)
        return false;
    }
    return true;
}

int main()
{
    long long int n,i;
    //string s;
    cin>>n;
    if(n==1)
    n++;
    while(true)
    {
        if(isBeautiful(n))
        break;
        n++;
    }
    cout<<n<<endl;
    return 0;
}