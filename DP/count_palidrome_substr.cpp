#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int CountSubstrPalindrome(string s)
{
    int i,j,k;
    int n=s.length();
    int mxl=0,cnt=0;

    vector<vector<bool> > dp(n,vector<bool> (n));
    for(k=0;k<n;k++)
    {
        for(i=0,j=k;i<n;j++,i++)
        {
            if(k==0)
            dp[i][i]=true;
            else if(k==1){
                if(s[i]==s[j])
                dp[i][j]=true;
                else
                dp[i][j]=false;
            }
            else{
               if(s[i]==s[j] && dp[i+1][j-1]==true)
                dp[i][j]=true;
                else
                dp[i][j]=false;
            }
        if(dp[i][j]){
        cnt++;
        mxl=k+1;
        }
        }
        
    }
    cout<<"Maximum length of palindrome in givem string:"<<mxl<<endl;
    return cnt;
}

int main()
{
    int n,i,j;
    string s;
    cin>>s;
    int ans=CountSubstrPalindrome(s);
    cout<<ans<<endl;
    return 0;
}