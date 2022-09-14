#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v,int l,int m,int r)
{
    int i=l;
    int j=m;
    int k=0;
    vector<int> temp(r-l+1);
    while(i<=(m-1) && j<=r)
    {
        if(v[i]<=v[j])
        {
            temp[k++]=v[i];
            i++;
        }
        else
        {
            temp[k++]=v[j];
            j++;
        }
    }
    while(i<=(m-1))
    {
        temp[k++]=v[i];
        i++;
    }
    while(j<=r)
    {
        temp[k++]=v[j];
        j++;
    }
    int x=0;
    for(int i=l;i<=r;i++)
    v[i]=temp[x++];
}

void merge_sort(vector<int> &v,int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(v,l,m);
        merge_sort(v,m+1,r);
        merge(v,l,m+1,r);
    }
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    merge_sort(v,0,n-1);
    for(i=0;i<n;i++)
    cout<<v[i]<<" ";
    return 0;
}