#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    vector<string> v(n);
    string alls="";
    stack<char> stk;
    int cnt,pos=-1;
    
    
    for(i=0;i<n;i++)
    cin>>v[i];
    sort(v.begin(),v.end());
    for(i=0;i<n;i++){
    
    int p=0;
    pos=-1;
    cnt=0;
    for(int j=0;j<alls.length() && p<v[i].length();j++)
    {
        if(alls[j]==v[i][p])
        {
            cnt++;
            pos=j;
            p++;
        }
        else{
            cnt=0;
            pos=-1;
            p=0;
        }
        
    }
    if(pos==-1)
    alls+=v[i];
    else{
        string part=v[i].substr(p,v[i].length()-p);
       // cout<<" Some parts only: "<<part<<endl;
        alls+=part;
    }
  //  cout<<alls<<endl;
    }
    cout<<"Res string: ";
    cout<<alls<<endl;
    return 0;

}