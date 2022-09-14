#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<int> v1,v2;
    int i,j;
    for(i=0;i<s1.length();i++)
    v1.push_back(s1[i]);
    for(i=0;i<s2.length();i++)
    v2.push_back(s2[i]);
    int sum=accumulate(v2.begin(),v2.end(),0);
    cout<<sum<<endl;
    for(i=0;i<s1.length()-s2.length();i++)
    {
        int s=accumulate(v1.begin()+i,v1.begin()+i+s2.length(),0);
        if(s==sum)
        cout<<i<<" ";
    }
    return 0;
}