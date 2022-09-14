#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <set>
#include <bits/stdc++.h>
using namespace std;

void allPermutations(string s,string out,set<string> &res,int n)
{
    if(s.length()==0){
        res.insert(out);
        return ;
    }
    string out1=out;
    string out2=out;
    char x=s[0];
    if(x>='a' && x<='z')
    out1.push_back(x-32);
    else if(x>='A' && x<='Z')
    out1.push_back(x+32);
    else
    out1.push_back(x);
    out2.push_back(x);
    s.erase(s.begin());
    allPermutations(s,out1,res,n);
    allPermutations(s,out2,res,n);
}

int main()
{
    int n,i,j;
    string s;
    cin>>s;
    set<string> res;
    allPermutations(s,"",res,n);
    set<string> ::iterator it;
    for(it=res.begin();it!=res.end();it++)
    cout<<*it<<" ";
    return 0;
}
