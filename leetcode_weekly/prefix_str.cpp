#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string longest_prefix(string s1,string s2)
{
    string p="";
    int i;
    for(i=0;i<min(s1.length(),s2.length());i++)
    {
        if(s1[i]==s2[i])
        p+=s1[i];
        else
        return p;
    }
    return p;

}

int main()
{
    int n,i,j;
    cin>>n;
    vector<string> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    string cmp=v[0];
    for(i=1;i<n;i++)
    {
        cmp=longest_prefix(cmp,v[i]);
    }
    cout<<cmp<<endl;
    return 0;
    
}