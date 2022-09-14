#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=1,p=2;
        n-=2;
        while(n--)
        {
            sum+=p;
            p+=2;
        }
        cout<<sum<<endl;
    }
return 0;
}