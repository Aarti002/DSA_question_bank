#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,i;
    cin>>t;
    while(t--){
    cin>>n;
    int cnt=2;
    
    for(i=1;i<n;i++)
    cnt+=min(i-1,n-i)+1;
    if(n>1)
    cnt++;
    cout<<cnt<<endl;
    }
    return 0;
}