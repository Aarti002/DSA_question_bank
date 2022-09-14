#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string> 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,i;
    cin>>t;
    string s;
    getline(cin,s);
    while(t--)
    {
        string ins;
         getline(cin, ins);
        int arr[26]={0};
        
        for(i=0;i<ins.length();i++){
            char x=tolower(ins[i]);
        arr[x-'a']=1;}
        string ans="";
        for(i=0;i<26;i++)
        {
            if(!arr[i])
            ans+='a'+i;
            //cout<<arr[i]<<" ";
        }
        if(ans.size()==0)
        cout<<'~'<<endl;
        else
        cout<<ans<<endl;
    }
    return 0;
}