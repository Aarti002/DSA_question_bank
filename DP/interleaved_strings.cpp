#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isInterleaved(string a,string b,string c,int n,int m,int l)
{
    if(l==0)
    return 1;
    
    bool x,y;
    if(b[m-1]==c[l-1])
    x=isInterleaved(a,b,c,n,m-1,l-1);
    if(a[n-1]==c[l-1])
    y=isInterleaved(a,b,c,n-1,m,l-1);
    return x||y;
}

int main()
{
    int n,m,i;
    string a,b,c;
    cin>>a>>b>>c;
    cout<<isInterleaved(a,b,c,a.length(),b.length(),c.length())<<endl;
    return 0;
}