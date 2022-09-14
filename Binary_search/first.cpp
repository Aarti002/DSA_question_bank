#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int isValid(vector<int> &v,int n,int sum,int k)
{
    int s=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        if((s+v[i])<=sum)
        s+=v[i];
        else
        {
            cnt++;
            s=v[i];
            if(s>sum)
            return false;
        }
        //cout<<"isvalid "<<s<<endl;
    }
    
    if(cnt<k)
    return true;
    else
    return false;
}

int minimize_maximum_book_page(vector<int> &v,int n,int s)
{//cout<<"inn\n";
    if(s>n)
    return -1;
    int str=INT_MIN;
    for(int i=0;i<n;i++)
    str=max(v[i],str);
   // int str=*min_element(v.begin(),v.end());
    int ed=accumulate(v.begin(),v.end(),0);
 //   cout<<str<<" "<<ed<<endl;
    int res=-1;
    while(str<=ed){
        //cout<<str<<" "<<ed<<endl;
        int md=str+(ed-str)/2;
        if(isValid(v,n,md,s))
        {
            res=md;
            ed=md-1;
        }
        else
        str=md+1;
    }
    return res;
}

int main()
{ 
    int i,n,std;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++){
     //   cout<<"New\n";
    cin>>v[i];}
    cin>>std;
    int ans=minimize_maximum_book_page(v,n,std);
    cout<<ans<<endl;
    
    return 0;
}