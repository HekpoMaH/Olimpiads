#include<bits/stdc++.h>
using namespace std;
const int nmax=1000009;
int a[nmax],mvs[4];
int m,k,l;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>k>>l>>m;
    a[0]=0;mvs[1]=1;mvs[2]=k;mvs[3]=l;
    for(int i=1;i<=nmax;i++)
    {
        for(int j=1;j<=3;j++)if(i-mvs[j]>=0&&a[i-mvs[j]]==0){a[i]=1;break;}
    }
    for(int i=1;i<=m;i++)
    {
        int n;
        cin>>n;
        if(a[n]==1)cout<<"A";
        if(a[n]==0)cout<<"B";
    }
    cout<<"\n";
}

