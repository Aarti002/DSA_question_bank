#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int i=0,j=s.length()-1;
    while(i<=j){
        if(s[i]!=s[j])
        return false;
        i++;
        j--;
    }
    return true;
}
void allPalindromePartition(string s,string out)
{
    if(s.length()==0){
        cout<<out<<endl;
        return ;
    }
    for(int i=0;i<s.length();i++){
        string ss=s.substr(0,i+1);
        string rem=s.substr(i+1,s.length());
        if(isPalindrome(ss))
        allPalindromePartition(rem,out+"("+ss+")");
    }
}

int main()
{
    int n,i;
    string s;
    cin>>s;
    allPalindromePartition(s,"");
    return 0;
}