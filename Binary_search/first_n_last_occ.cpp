#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int low_index(vector<int> &v,int val)
{
    int low=0;
    int high=v.size()-1;
    int m=high/2;
    while(low<high)
    {
        if(v[m]<val)
        low=m+1;
        else
        high=m-1;
        m=low+(high-low)/2;
    }
    if(low<v.size() && v[low]==val)
    return low;
    return -1;
}


int high_index(vector<int> &v,int val)
{
    int low=0;
    int high=v.size()-1;
    int m=high/2;
    while(low<=high)
    {
        if(v[m]<=val)
        low=m+1;
        else
        high=m-1;
        m=low+(high-low)/2;
    }
    if(high==-1)
    return -1;
    if(high<v.size() && v[high]==val)
    return high;
    return -1;
}

int main()
{
    int n,i,val;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    cin>>val;
    int l=0,h=n-1,m;
    m=h/2;
    int first_occ=low_index(v,val);
    int last_occ=high_index(v,val);
    cout<<first_occ<<" "<<last_occ<<endl;
    return 0;
}