#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &v,vector<int> &temp,int l,int m,int r)
{
    int i=l;
    int j=m;
    int ii=l;
    int cnt=0;
    while(i<=(m-1) && j<=r)
    {
        if(v[i]<=v[j])
        {
            temp[ii++]=v[i];
            i++;
        }
        else 
        {
           temp[ii++]=v[j];
            j++;
            cnt+=(m-i);
        }
    }
    while(i<=(m-1))
    {
        temp[ii++]=v[i];
        i++;
    }
    while(j<=r)
    {
        temp[ii++]=v[j];
        j++;
    }
    for(i=l;i<=r;i++)
    v[i]=temp[i];
    return cnt;
}

int mergeSort(vector<int> &v,int l,int r)
{
    int cnt=0;
    vector<int> temp(v.size());
    if(r>l){
    int m=(l+r)/2;
    cnt+=mergeSort(v,l,m);
    cnt+=mergeSort(v,m+1,r);
    cnt+=merge(v,temp,l,m+1,r);
    }
    return cnt;
}

void countInversions(vector<int> &v,int n,int &cnt)
{
    int ans=mergeSort(v,0,n-1);
    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
    cout<<ans<<endl;
}

int main()
{
    int n,i,x;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int cnt=0;
    countInversions(v,n,cnt);
    //cout<<cnt<<endl;
    return 0;
}