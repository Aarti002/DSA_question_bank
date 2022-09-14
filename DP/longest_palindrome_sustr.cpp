#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,j,i; 
    string s;
    cin>>s;
    n=s.length();
    string ans="";
    ans+=s[0];
    int mxl=1,start=0,g;
    vector<vector<int> > pal(n,vector<int>(n,0));
    for(g=0;g<n;g++)
    {
        for(i=0,j=g;j<n;j++,i++)
        {
            if(i==j)
            pal[i][j]=1;
            else if((j-i)==1)
            {
                if(s[i]==s[j])
                pal[i][j]=1;
                else
                pal[i][j]=0;
            }
            else{
                if(s[i]==s[j])
                pal[i][j]=pal[i+1][j-1];
                else
                pal[i][j]=0;
            }
            if(pal[i][j]){
                if(ans.size()<(j-i+1))
                ans=s.substr(i,(j-i+1));
            mxl=g+1;
            }
        }
    }
    cout<<ans<<" "<<mxl<<endl;
    return 0;
}