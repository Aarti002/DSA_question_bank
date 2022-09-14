#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,k;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    cin>>k;
    int l=0,cnt=0,pro=1;
    for(i=0;i<n;i++)
    {
        pro*=v[i];
        while(pro>=k)
        {
            pro/=v[l];
            l++;
        }
        
        cnt+=(i-l+1);
    }
    cout<<cnt<<endl;
    return 0;
}