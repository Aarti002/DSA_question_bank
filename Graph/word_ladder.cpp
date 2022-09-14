#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int bfs(vector<string> &wl,string s,string e)
{
    set<string> dict(wl.begin(),wl.end());
    if(find(wl.begin(),wl.end(),e)==wl.end())
    return 0;
    queue<string> q;
    q.push(s);
    int ans=1;
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            string chk=q.front();
            q.pop();
            if(chk==e)
            return ans;
            if(dict.count(chk))
            dict.erase(chk);
            for(int i=0;i<e.length();i++)
            {
                char c=chk[i];
                for(int j=0;j<26;j++)
                {
                    chk[i]='a'+j;
                    if(dict.count(chk))
                    q.push(chk);
                }
                chk[i]=c;
            }

        }
        ans++;
    }
    return 0;
}

int main()
{
    int n,i,j;
    string s,e;
    cin>>s>>e;
    cin>>n;
    vector<string> wordList(n);
    for(i=0;i<n;i++)
    cin>>wordList[i];
    int ans=bfs(wordList,s,e);
    cout<<"Minimum number of transformation from s to e: "<<ans<<endl;
    return 0;
}