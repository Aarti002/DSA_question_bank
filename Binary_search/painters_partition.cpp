#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int isPossible(vector<int> &v,int n,int s,int k)
{
    int sum=0,cnt=1;
    for(int i=0;i<n;i++)
    {
        if((sum+v[i])<=s)
        sum+=v[i];
        else{
            sum=v[i];
            cnt++;
            if(sum>s)
            return false;
        }
        
    }
    if(cnt>k)
    return false;
    return true;
}

int min_time_paint(vector<int> &v,int n,int t,int p)
{
    int e=accumulate(v.begin(),v.end(),0)*t;
    int s=0;
    int ans=-1;
    while(s<=e)
    {
        int m=s+(e-s)/2;
        if(isPossible(v,n,m/t,p)){
           e=m-1;
           ans=m;
        }
        else
        s=m+1;
    }
    return s;
}

int main()
{
    int n,t,i,p;
    cin>>n>>p;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    cin>>t;
    int ans=min_time_paint(v,n,t,p);
    cout<<ans<<endl;
    return 0;
}