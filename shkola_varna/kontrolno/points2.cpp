#include<iostream>
using namespace std;
long long n,a[100009][3],s,ps[100009][3],s2,kva;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2],ps[i][1]=ps[i-1][1]+a[i][1],ps[i][2]=ps[i-1][2]+a[i][2],kva+=a[i][1]*a[i][1]+a[i][2]*a[i][2];
    s+=(n-1)*kva;
    for(int i=1;i<=n;i++)
    {
        s2+=(ps[n][1]-ps[i][1])*a[i][1];
        s2+=(ps[n][2]-ps[i][2])*a[i][2];
    }
    cout<<s-2*s2<<endl;
}

