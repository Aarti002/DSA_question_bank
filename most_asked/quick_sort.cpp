#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v,int lb,int ub)
{
    int pvt=v[lb];
    int start=lb,end=ub;
    while(start<end)
    {
        while(v[start]<=pvt)
        start++;
        while(v[end]>pvt)
        end--;
        if(start<end)
        swap(v[start],v[end]);
    }
    swap(v[lb],v[end]);
    return end;
}

void quick_sort(vector<int> &v,int lb,int ub)
{
   if(lb<ub){
    int pvt=partition(v,lb,ub);
    quick_sort(v,lb,pvt-1);
    quick_sort(v,pvt+1,ub);
   }
    
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    quick_sort(v,0,n-1);
    for(i=0;i<n;i++)
    cout<<v[i]<<" ";
    return 0;
}