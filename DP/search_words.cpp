#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPresent(vector<string> &d,string s)
{
    for(int i=0;i<d.size();i++)
    {
        if(d[i]==s)
        return true;
    }
    return false;
}
set<string> ans;
void findWord(vector<string> &d,vector<vector<char> > &words,int i,int j,vector<vector<int> > &vis,string s,int n,int m)
{
    vis[i][j]=1;
    s+=words[i][j];
    if(isPresent(d,s))
    ans.insert(s);
    for(int x=i-1;x<=i+1 && x<n;x++)
    {
        for(int y=j-1;y<=j+1 && y<m;y++)
        {
            if(x>=0 && y>=0 && vis[x][y]==0)
            findWord(d,words,x,y,vis,s,n,m);
        }
    }
    vis[i][j]=0;
    s.erase(s.length()-1);
}

int main()
{
    int n,p,q,i,j;
    cin>>n;
    vector<string> dict(n);
    
    for(i=0;i<n;i++)
    cin>>dict[i];
    cin>>p>>q;
    vector<vector<char> > srch(p,vector<char>(q));
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        cin>>srch[i][j];
    }
    vector<vector<int> > vis(p,vector<int>(q,0));
    string s="";
    //WE WILL BE USING SUCH APPROACH IN WHICH WE WILL CREATE ALL POSSIBLE STRING FROM BOGGLE
    // AND WILL CHECK IS THAT CREATED STRING PRESENT IN DICTIONARY OR NOT!
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            
            findWord(dict,srch,i,j,vis,s,p,q);
        }
    }
    set<string> ::iterator it;
    for(it=ans.begin();it!=ans.end();it++)
    cout<<*it<<" ";
    return 0;

}