#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int n)
{
    int i=0,j=n-1;
    while(i<=j) 
    {
        if(s[i]!=s[j])
        return false;
        i++;
        j--;
    }
    return true;
}

int min_insert_to_make_palindrome(string s,int n)
{
    int c=0,f=0;
    while(s.length()>0)
    {
        if(isPalindrome(s,s.length()))
        return c;
        else{
        s.pop_back();
        c++;
        }

    }
return 0;
}
int dp[1001][1001];
int lps(string s, int n)
{
    int len=0;
    vector<int> lpc(n);
    lpc[0]=0;
    int i=1;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            len++;
            lpc[i]=len;
            i++;
        }
        else{
            if(len!=0)
            len=lpc[len-1];
            else
            {
                lpc[i]=0;
                i++;
            }
        }
    }
    return lpc[n-1];
}
 

int main()
{
    int i,n;
    string s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
 //   int minChr=min_insert_to_make_palindrome(s,n);
    string s1=s;
    reverse(s1.begin(),s1.end());
    s+='$';
    s+=s1;
    int lcp=lps(s,n);
  //  cout<<minChr<<endl;
    cout<<n-lcp<<endl;
    return 0;
}