#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int bfs(vector<string> &bank,string s,string e)
{
    unordered_set<string> st(bank.begin(),bank.end());
    queue<string> q;
    q.push(s);
    if(find(bank.begin(),bank.end(),e)==bank.end())
    return -1;
    int i,ans=0;
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            string chk=q.front();
            q.pop();
            if(chk==e)
            return ans;
            st.erase(chk);
            for(i=0;i<8;i++)
            {
                string p=chk;
                p[i]='A';
                if(st.count(p))
                q.push(p);
                p[i]='C';
                if(st.count(p))
                q.push(p);
                p[i]='G';
                if(st.count(p))
                q.push(p);
                p[i]='T';
                if(st.count(p))
                q.push(p);
            }
        }
    ans++;
    }
    return -1;
}

int main()
{
    int n,i,j;
    string s,e;
    cin>>s>>e;
    cin>>n;
    vector<string> bank(n);
    for(i=0;i<n;i++)
    cin>>bank[i];
    int ans=bfs(bank,s,e);
    cout<<ans<<endl;
    return 0;
}