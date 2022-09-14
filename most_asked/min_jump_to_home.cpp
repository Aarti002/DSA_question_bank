#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;


class NewOrg{
    public: 
    string org= "";
    vector<int> in_out;
    //constructor
    NewOrg(string name)
    {
        this->org = name;
        for(int i=0; i<25; i++)
            in_out.push_back(0);
    }
    //for adding new car
    void newCar(int start, int end)
    {
        for(int i=start; i<end; i++)
        {
            this->in_out[i]+=1;
        }
    }
};

int totalBill(int N)
{
    if(N==0)
        return 0;
    else if(N==1)
        return 100;
    else if(N==2)
        return 150;
    else if(N==3)
        return 200;
    int ans = 200+(N-3)*20;
    return ans;
}

int solve(vector<int> &cars)
{
    int ans = 0;
    for(auto c:cars)
        ans+= totalBill(c);
    return ans;
}

vector<string> inputs(string &s)
{
    vector<string> res;
    string ss= "";
    for(int i=0;i<=s.length();i++)
    {
        if(s[i]==',' || i==s.length())
        {
            res.push_back(ss);
            ss = "";
            i++;
        }
        ss+=s[i];
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    map<string, NewOrg*> mp;
    while(n--)
    {
        string temp;
        cin>>temp;
        vector<string> newc = inputs(temp);
        NewOrg* org = new NewOrg(newc[0]);
        if(mp.find(newc[0])==mp.end())
            mp[newc[0]] = org;
        int start = stoi(newc[1]);
        int end = stoi(newc[2]);
        mp[newc[0]]->newCar(start, end);
    }
    
    for(auto it: mp)
    {
        int res = solve(it.second->in_out);
        cout<<it.first<<" bill: "<<res<<endl;
    }
    return 0;
}