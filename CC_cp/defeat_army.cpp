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
        if(a>(b+c) || b>(c+a) || c>(a+b))
        cout<<"YES\n";
        else
        cout<<"NO\n";

    }
    return 0;
}