#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &v,int i,int j,int t)
{
   // int i=0,j=n-1;
    while(i<=j)
    {
        int m=i+(j-i)/2;
        if(v[m]==t)
        return m;
        if(v[m]>t)
        j=m-1;
        else
        i=m+1;
    }
    return -1;
}

int findPivot(vector<int> &v,int n)
{
    int i=0,j=n-1;
    while(i<=j)
    {
        int m=i+(j-i)/2;
        if(v[m]<v[m-1] && v[m]<v[m+1])
        return m;
        if(v[m]>v[m-1] && v[m]<v[m+1])
        j=m-1;
        else
        i=m+1;
    }
    return j;
}

int findElement(vector<int> &v,int n,int t)
{
    int i=0,j=n-1;
    while(i<=j)
    {
        int m=(i+j)/2;
        if(v[m]==t)
        return m;
        if(v[m]>v[i])
        {
            if(t>=v[i] && t<=v[m])
            j=m-1;
            else
            i=m+1;
        }
        else{
            if(t<=v[j] && t>=v[m])
            i=m+1;
            else
            j=m-1;
        }
    }
    return -1;
}

int main()
{
    int n,i,target;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    cin>>target;
    int pvt=findPivot(v,n);
    if(v[pvt]==target)
    cout<<pvt<<endl;
    else{
   int pos1=binary_search(v,0,pvt-1,target);
   int pos2=binary_search(v,pvt+1,n,target);
   if(pos1!=-1)
    cout<<pos1<<endl;
    else if(pos2!=-1)
    cout<<pos2<<endl;
    else
    cout<<"Not possible\n";
    }
    cout<<endl<<findElement(v,n,target)<<endl;
    return 0;
}