#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int n,x,i,j;
    cin>>n;
    vector<vector<int> > p(n,vector<int>(2));
    for(i=0;i<n;i++)
    {
        cin>>p[i][0]>>p[i][1];
    }
    sort(p.begin(),p.end());
    int ans=0;
    for(i=0;i<n;i++)
    {unordered_map<double,int> mp;
        for(j=i+1;j<n;j++)
        {
            if(p[i][0]==p[j][0])
            mp[INT_MAX]++;
            else{
                double slp=(p[j][1]-p[i][1])/(p[j][0]-p[i][0]);
                mp[slp]++;
            }
        }
        unordered_map<double,int> ::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    ans=max(ans,it->second);
    }
    cout<<ans<<endl;
    return 0;

}