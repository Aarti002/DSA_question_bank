#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int max_subset_sum(vector<int> &v,int n)
{
    int i,j;
    int inc=v[0],exc=0;
    for(i=1;i<n;i++)
    {
        int ninc=exc+v[i];
        int nexc=max(inc,exc); 
        exc=nexc;
        inc=ninc;
    }
    return max(inc,exc);
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int mx_sum=max_subset_sum(v,n);
    cout<<mx_sum<<endl;
    return 0;
}