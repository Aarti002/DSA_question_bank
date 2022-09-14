#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findIndex(vector<int> &v,int n)
{
    int l=0,h=n-1;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(v[m]<v[m-1] && v[m]<v[m+1])
        return v[m];
        if(v[m]>v[m-1] && v[m]<v[m+1])
        h=m-1;
        else
        l=m+1;
    }
    return v[0];
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int ind=findIndex(v,n);
    if(ind==-1)
    cout<<"Already sorted!\n";
    else
    cout<<ind<<endl;
    return 0;
}