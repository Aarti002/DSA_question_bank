#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,r;
    string s;
    cin>>s;
    cin>>r;
    vector<int> v(s.length(),-1);
    string a="";
    int l=1;
//     while(r>0)
//     {
//         int stp=(r-1)+(r-2);
//         int p=0;
//         cout<<stp<<endl;
//         for(i=0;i<s.length();i++)
//         {
//             if(v[i]==-1)
//             {
//                 ans+=s[i];
//                 cout<<s[i];
//                 i+=stp;
//                 v[i+1]=stp;
//             }
//         }
//       //  l++;
// r-=1;
//     }
string ans[r];
int y=0;
int flag=1;
    for(i=0;i<s.length();i++)
    {
        ans[y]+=s[i];
        if(y==0)
        flag=1;
        if(y==r-1)
        flag=0;
        if(flag)
        y++;
        else
        y--;

    }
    for(i=0;i<r;i++)
    a+=ans[i];
    cout<<a<<endl;
    return 0;
}