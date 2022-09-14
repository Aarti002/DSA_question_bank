#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        int cnt=0;
        for(i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
            cnt++;
        }
        int ans=0;
        if(cnt%2!=0)
        ans=1;
        else if(cnt!=0 && cnt%2==0)
        ans=2;
        cout<<ans<<endl;
    }
    return 0;
}