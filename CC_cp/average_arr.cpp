#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,i,avg;
    cin>>t;
    while(t--)
    {
        cin>>n>>avg;
        vector<int> s(n);
        for(i=0;i<n;i++)
        cin>>s[i];
      //  int sum=accumulate(s.begin(),s.end(),0);
        int mx=*max_element(s.begin(),s.end());
        int mn=*min_element(s.begin(),s.end());
        if(mx<avg || mn>avg)
        cout<<"NO\n";
        else
        cout<<"YES\n";
    }
    return 0;
}