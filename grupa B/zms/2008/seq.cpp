#include<bits/stdc++.h>
using namespace std;
int s;
long long a[128][128],n;
int main()
{
    cin>>s>>n;
    for(int i=0;i<=s;i++)
    {
        if(i<10)a[i][1]=1;
        else a[i][1]=0;
    }
    int k=1;
    while(a[s][k]<n)
    {
        k++;
        a[0][k]=1;
        for(int i=1;i<=s;i++)
        {
            if(i<10)a[i][k]=a[i-1][k]+a[i][k-1];
            else a[i][k]=a[i-1][k]+a[i][k-1]-a[i-10][k-1];
        }
    }
    for(int k1=k;k1>1;k1--)
    {
        int p=0;
        long long f=a[s][k1-1];
        while(f<n)
        {
            p++;
            f+=a[s-p][k1-1];
        }
        cout<<p;
        n-=f;n+=a[s-p][k1-1];s-=p;
    }
    cout<<s<<endl;
    return 0;
}
