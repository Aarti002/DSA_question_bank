#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(char s,char h,char d,int n)
{
    if(n==0)
    {
        //cout<<"All done!\n";
        return ;
    }
    towerOfHanoi(s,h,d,n-1);
    cout<<s<<" "<<h<<" "<<d<<" ->"<<n<<endl;
    towerOfHanoi(h,d,s,n-1);
    return ;
}

int main()
{
    int n,i;
    cin>>n;
    towerOfHanoi('s','h','d',n);
    return 0;
}