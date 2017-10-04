#include<iostream>
using namespace std;
int n,m,a[111][111];
bool xyu()
{
    int b[111][111];int l=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]+1==a[i-1][j]||a[i][j]+1==a[i][j-1]||a[i][j]+1==a[i+1][j]||a[i][j]+1==a[i][j+1])b[i][j]=a[i][j]+1,l=1;
            else b[i][j]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)a[i][j]=b[i][j];
    }

    if(l==0)return false;
    return true;
}
int t;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    while (xyu()==true)t++;
    cout<<t<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
