#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,p,i;
    cin>>n>>p;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    sort(v.begin(),v.end());
    int a=n/p;
    int mn=INT_MAX,mx=INT_MIN;
    i=0;
    
    for(i=0;i<n;i+=a)
    {cout<<v[i]<<endl;
        mn=min(mn,v[i]);
        mx=max(mx,v[i]);
    }
    cout<<mx-mn<<endl;
    return 0;
}