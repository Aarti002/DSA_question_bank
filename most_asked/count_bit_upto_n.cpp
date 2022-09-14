#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int max2power(int n)
{
    int x=0;
    while((1<<x)<=n)
    {
        x++;
    }
    return x-1;
}

int countBits(int n)
{
    if(n==0)
    return 0;
    int x=max2power(n);
    int max2power=(1<<(x-1))*(x);               //as n>>1 -->divides n by 2 similerly 1<<n-->multilies n by 2
    int rembits=(n-(1<<x)+1);
    int rem=n-(1<<x);
    int ans=max2power+rembits+countBits(rem);
    return ans;

}

int main()
{
    int n,i,j;
    cin>>n;
    int ans=countBits(n);
    cout<<ans<<endl;
    return 0;
}