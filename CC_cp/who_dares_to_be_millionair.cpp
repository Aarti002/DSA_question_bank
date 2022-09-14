#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string chef,act;
        cin>>act;
        cin>>chef;
        int cnt=0;
        vector<int> v(n+1);
        for(i=0;i<=n;i++)
        cin>>v[i];
        for(i=0;i<n;i++)
        {
            if(chef[i]==act[i])
            cnt++;
        }
        cout<<v[cnt]<<endl;
    }
    return 0;
}