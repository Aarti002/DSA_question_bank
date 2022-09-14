#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> v(n+2);
        int tot=pow(2,n);
        int flag=0;
        cout<<tot<<endl;
        
        for(i=1;i<=n-1;i++)
        v[i]=i;
        int p=(n-1)*n/2;
        int x=n/2;
        if(x%2!=0)
        v[i-1]++;
        v[n]=(tot-p)/2;
        v[n+1]=(tot-p)/2;
        for(i=1;i<=n+1;i++)
        cout<<v[i]<<" ";
        cout<<endl;
    }
    return 0;
}