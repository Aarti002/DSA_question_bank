#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    if (s == "")
        return false;
    if (s.length() > 3)
        return false;
    cout << "s len:" << s.length() << endl;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            continue;
        else
            return false;
    }
    int p = stoi(s);
    //   cout<<p<<endl;
    if (p >= 0 && p <= 255)
        return true;
    return false;
}

int main()
{
    string s;
    cin >> s;
    int dot = count(s.begin(), s.end(), '.');
    if (dot != 3)
        cout << "Nope!\n";
    else
    { 
        int flag = 0;
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '.')
            { // cout<<res<<endl;
                if (!isValid(res))
                {
                    flag = 1;
                    break;
                }
                res = "";
                //  i++;
            }
            else
                res += s[i];
        }
        //  cout<<res<<endl;
        if (!isValid(res))
            flag = 1;
        if (flag == 1)
            cout << "Nope! flag\n";
        else
            cout << "Yes\n";
    }
    return 0;
}