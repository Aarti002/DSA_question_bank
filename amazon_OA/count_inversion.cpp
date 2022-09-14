#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int count_inversion(vector<int> &v1,vector<int> &v2,int n)
{
    
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v1(n),v2(n);
    for(i=0;i<n;i++)
    cin>>v1[i];
    for(i=0;i<n;i++)
    cin>>v2[i];
    cout<<count_inversion(v1,v2,n)<<endl;
    return 0;
}