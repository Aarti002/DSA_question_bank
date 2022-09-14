#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    string s;
    cin>>s;
    n=s.length();
    //we have to count no of a..b..c.. type of sequences---> 
    //types of situations:
    //a type--> 1) will create new sequence from scratch/will not get append or will get append to existing seq.
    //ab type--> 2) will append to already existing sequences ab.. or will not get append + will get attached to a type of seq.
    ///abc type---> 3) will get append to exsisting one or will not get append + will get append to ab type
    int a_type=0,ab_type=0,abc_type=0;
    for(i=0;i<n;i++){
        char c=s[i];
        if(c=='a')
        a_type=2*a_type+1;
        else if(c=='b')
        ab_type=2*ab_type+a_type;
        else if(c=='c')
        abc_type=2*abc_type+ab_type;
    }
    cout<<abc_type<<endl;
    return 0;
}