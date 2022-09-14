#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a,vector<int> &b)
{
    return (a[1]*a[2])>(b[1]*b[2]);
}

int main()
{
    int n,i,j;
    cin>>n;
    vector<vector<int> > box(n);
    int w,d,h;
    for(i=0;i<n;i++)
    {
        cin>>h>>d>>w;
        box[i]={h,d,w};         //0th->length ,1st->width, 2nd->height
    }
    vector<vector<int> > rot(3*n,vector<int>(3));
    int ind=0;
    for(i=0;i<n;i++)
    {//on the basis of height-->first rotation
        rot[ind][0]=box[i][0];
        rot[ind][1]=max(box[i][1],box[i][2]);
        rot[ind][2]=min(box[i][1],box[i][2]);
        ind++;
        //on the basis of depth-->second rotation
        rot[ind][0]=box[i][1];
        rot[ind][1]=max(box[i][0],box[i][2]);
        rot[ind][2]=min(box[i][0],box[i][2]);
        ind++;
        //on the basis of width-->third rotation
        rot[ind][0]=box[i][2];
        rot[ind][1]=max(box[i][1],box[i][0]);
        rot[ind][2]=min(box[i][1],box[i][0]);
        ind++;
    }
    n=3*n;
    sort(rot.begin(),rot.end(),compare);
    for(i=0;i<n;i++)
    {
        cout<<"Length breath and height: ";
        cout<<rot[i][0]<<" "<<rot[i][1]<<" "<<rot[i][2]<<endl;
        cout<<"With base area: "<<rot[i][0]*rot[i][1]<<endl;
    }
    vector<int> mxh(n);
    for(i=0;i<n;i++)
    {
      mxh[i]=rot[i][0];  
    }
    //now its LIS
 //   vector<int> ans(n,0);
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(rot[j][1]>rot[i][1] && rot[j][2]>rot[i][2] && mxh[i]<mxh[j]+rot[i][0])
            mxh[i]=mxh[j]+rot[i][0];
        }
    }
    int ans=INT_MIN;
    for(i=0;i<n;i++)
    {
        if(mxh[i]>ans)
        ans=mxh[i];
    }
    cout<<ans<<endl;
    return 0;
}