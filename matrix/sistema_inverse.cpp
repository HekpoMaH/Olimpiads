#include<bits/stdc++.h>
using namespace std;
double a[100][100],b[100],ans[100];
double inv[100][100];
double cra[100],cri[100];
int n,m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>a[i][j];
        inv[i][i]=1;
    }
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int k=1;k<=n;k++)
    {
        double del=a[k][k];
        for(int i=k;i<=n;i++)
        {
            a[k][i]/=del;
            //inv[k][i]/=a[k][k];
        }
        for(int i=1;i<=n;i++)inv[k][i]/=del;
        for(int i=1;i<=n;i++)
        {
            if(i==k)continue;
            for(int j=1;j<=n;j++)cra[j]=a[k][j],cri[j]=inv[k][j];
            for(int j=1;j<=n;j++)
            {
                cra[j]*=-a[i][k];
                cri[j]*=-a[i][k];
            }
            for(int j=1;j<=n;j++)a[i][j]+=cra[j],inv[i][j]+=cri[j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
        cout<<"|";
        for(int j=1;j<=n;j++)cout<<inv[i][j]<<" ";
        cout<<endl;
    }

    for(int i=1;i<=n;i++)
    {
        double o=0;
        for(int j=1;j<=n;j++)
        {
            o+=inv[i][j]*b[j];
        }
        ans[i]=o;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}

