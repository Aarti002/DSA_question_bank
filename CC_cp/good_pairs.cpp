#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> a(n),b(n);
        map<int,int> mp;
        for(i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
        }
        for(i=0;i<n;i++)
        cin>>b[i];
        int cnt=0;
        for(i=0;i<n;i++)
        {
            if(find(b.begin()+i+1,b.end(),a[i])!=b.end())
            cnt++;
        }
        for(i=0;i<n;i++)
        {
            if(find(a.begin()+i+1,a.end(),b[i])!=a.end())
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}