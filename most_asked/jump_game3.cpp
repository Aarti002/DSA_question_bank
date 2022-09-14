#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &v,int n,int s)
{
    if(v[s]>=0 && s>=0 && s<n)
    {
        v[s]=-v[s];
        return v[s]==0 || isPossible(v,n,s-v[s]) || isPossible(v,n,s+v[s]);
    }
   return false;
}

int main()
{
    int n,i,s;
    cin>>n;
    vector<int> v(n);
    cin>>s;
    for(i=0;i<n;i++)
    cin>>v[i];
    cout<<isPossible(v,n,s)<<endl;
    return 0;
}