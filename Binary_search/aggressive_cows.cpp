#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool canPlaceHere(vector<int> &v,int n,int c,int d)
{
    int str=v[0],i,cnt=1;
    for(i=1;i<n;i++)
    {
        if((v[i]-str)>=d){
            cnt++;
            str=v[i];
        }
        
    }
    if(cnt>=c)
        return true;
    return false;
}

int largest_min_distance(vector<int> &v,int n,int cows)
{
    int low=1,high=v[n-1]-v[0];
    while(low<=high)
    {
        int m=low+(high-low)/2;
        if(canPlaceHere(v,n,cows,m))
        {
            low=m+1;
        }
        else
        high=m-1;
    }
    return high;
}

int main()
{
    int n,i,cows;
    cin>>n>>cows;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    sort(v.begin(),v.end());
    int lmd=largest_min_distance(v,n,cows);
    cout<<lmd<<endl;
    return 0;
}