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
        //cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        int d=abs(a-b);
        if(abs(c-d)<d)
        cout<<abs(c-d+1)<<endl;
        else
        cout<<d<<endl;

    }
    return 0;
}