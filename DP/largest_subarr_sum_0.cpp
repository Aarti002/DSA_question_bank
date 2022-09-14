#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,sum=0,j;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    map<int,int> mp;
    int ans=-1;
    mp[sum]=-1;
    i=-1;
    while(i<n-1)
    {i++;
        sum+=v[i];
        
        if(mp.count(sum)==0)
        mp[sum]=i;
        else
        {
            int x=i-mp[sum];
           //8 mp[sum]=i;
            ans=max(ans,x);
        }
    }
    cout<<ans<<endl;
    return 0;
}