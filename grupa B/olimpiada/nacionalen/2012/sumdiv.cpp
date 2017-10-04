#include<iostream>
using namespace std;
int a[1002],d[1002][1002];
int n,k;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int j=0;j<k;j++)d[1][j]=(a[1]%k==j)? 1:0;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            int r=a[i]%k;
            int p=j-r;
            if(p<0)p+=k;
            int mx=0;
            for(int t=1;t<i;t++)mx=max(mx,d[t][p]);
            if(mx>0)d[i][j]=mx+1;
            else d[i][j]=(a[i]%k==j) ? 1:0;

        }
    }
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        mx=max(d[i][0],mx);
    }
    cout<<mx<<endl;
}
