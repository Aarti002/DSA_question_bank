#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i;
    cin>>n>>m;
    vector<int> bit(32,0);
    for(i=n;i<=m;i++)
    {
        while(i!=0)
        {
            if(i&1)
            bit[i]++;
            i=i<<1;
        }
    }
    for(i=0;i<32;i++)
    cout<<bit[i]<<" ";
    return 0;
}