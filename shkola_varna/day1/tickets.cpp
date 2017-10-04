#include<bits/stdc++.h>
using namespace std;
int n,a[100];
int dp[100][100],haha,m1;
void batrak(int l,int r,int p1,int p2,int hod)
{

    m1=max(p1,m1);if(l>r)return;
    if(hod%2==1)
    {
        if(a[l]>a[r])batrak(l+1,r,p1+a[l],p2,hod+1);
        if(a[r]<a[l])batrak(l,r-1,p1+a[r],p2,hod+1);
    }
    if(hod%2==0)
    {
        if(a[l]>a[r])batrak(l+1,r,p1,p2+a[l],hod+1);
        if(a[r]>a[l])batrak(l,r-1,p1,p2+a[r],hod+1);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    batrak(1,n,0,0,1);
    cout<<m1<<endl;
}
