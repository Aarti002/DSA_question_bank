#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int peak_element(vector<int> &v,int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
        int m=i+(j-i)/2;
        if(v[m]==v[i])
        i++;
        else if(v[m]<v[i])
        j=m-1;
        else
        i=m;
    }
    return v[i];
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int peak_ele=peak_element(v,n);
    cout<<peak_ele<<endl;
    return 0;
}