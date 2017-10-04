#include<bits/stdc++.h>
using namespace std;
int a[100009];
int m[100009];
int n,l,lef,righ,mid;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int j=0;
        lef=1;
        righ=l;
        while(lef<=righ)
        {
            mid=(lef+righ)/2;
            if(a[m[mid]]<=a[i])lef=mid+1,j=mid;
            else righ=mid-1;
        }

        if(j==l||a[i]<a[m[j+1]])
        {
            m[j+1]=i;
            l=max(l,j+1);
        }
    }
    cout<<l<<endl;
}
