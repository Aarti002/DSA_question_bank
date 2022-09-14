#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,t,j,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> a(n),b(n);
        map<pair<int,int>,int> mp;
        for(i=0;i<n;i++)
        cin>>a[i];
        for(i=0;i<n;i++)
        cin>>b[i];
        int ans=0;
        for(i=0;i<n;i++)
        {
            
            ans+=mp[{b[i],a[i]}];
            mp[{a[i],b[i]}]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}