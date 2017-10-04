#include<bits/stdc++.h>
using namespace std;
double w[200][200];
int n;
double a[200][200],b[200][200];
double eps=1e-9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>w[i][j];
        }
    }
    double mid;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            a[i][j]=a[j][i]=(w[i][j]+w[j][i])/2.0;mid=(w[i][j]+w[j][i])/2.0;
            b[i][j]=w[i][j]-a[i][j];
            b[j][i]=w[j][i]-a[j][i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<setiosflags(ios::fixed)<<setprecision(6)<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<setiosflags(ios::fixed)<<setprecision(6)<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}
