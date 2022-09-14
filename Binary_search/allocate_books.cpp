#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &v,int m,int b,int tot)
{
    int cnt=0,sum=0;
    for(int i=0;i<m;i++)
    {
        if((v[i]+sum)>tot)
        {
            sum=v[i];
            cnt++;
            if(sum>tot)
            return false;
        }
        else{
            sum+=v[i];
        }
    }
    if(cnt<b)
    return true;
    return false;
}

int min_max_days(vector<int> &v,int m,int n)
{
    int low=*min_element(v.begin(),v.end()),high=accumulate(v.begin(),v.end(),0);
    while(low<=high)
    {
        int md=low+(high-low)/2;
        if(isPossible(v,m,n,md))
        high=md-1;
        else
        low=md+1;
    }
    return low;
}

int main()
{
    int n,m,i;
    cin>>m>>n;
    vector<int> v(m);
    for(i=0;i<m;i++)
    cin>>v[i];
   // sort(v.begin(),v.end());
    int minDays=min_max_days(v,m,n);
    cout<<minDays<<endl;
    return 0;
}