#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int i,int j)
{
    while(i<=j)
    {
        if(s[i]!=s[j])
        return false;
        i++;
        j--;
    }
    return true;
}

int possible_partition(string s,int i,int n)
{
    if(i>=n || isPalindrome(s,i,n))
    return 0;
    int ans=INT_MAX,cnt=0;
    for(int p=i;p<n;p++)
    {
        cnt=1+possible_partition(s,i,p)+possible_partition(s,p+1,n);
        ans=min(ans,cnt);   
    }
    return ans;

}

int main()
{
    int n,i;
    string s;
    cin>>s;
    n=s.length();
    int ans=possible_partition(s,0,n-1);
    cout<<ans<<endl;
    return 0;
}
