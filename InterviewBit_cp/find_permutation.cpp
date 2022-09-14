#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v(n);
    for(i=0;i<n;i++)
    v[i]=i+1;
    int D=count(s.begin(),s.end(),'D');
    int I=count(s.begin(),s.end(),'I');
    int l=n,k=1;
    
        for(i=0;i<n-1;i++)
        {
            if(s[i]=='D'){
            v[i]=l;
            l--;
            }
            else{
            v[i]=k;
            k++;
            }
        }
    if(D>I)
    v[n-1]=l;
    else
    v[n-1]=k;
    for(i=0;i<n;i++)
    cout<<v[i]<<" ";
    return 0;

}