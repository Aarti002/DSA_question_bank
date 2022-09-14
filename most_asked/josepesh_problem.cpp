#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,k;
    cin>>n>>k;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    i=0;

    while(v.size()!=1)
    {
        int pos=(i+k-1)%v.size();
        cout<<v[pos]<<" ";
        v.erase(v.begin()+pos);
       i=pos;
    }
    cout<<"Winner: "<<v[0]<<endl;
    return 0;
}