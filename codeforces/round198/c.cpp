#include<bits/stdc++.h>
using namespace std;
long long a[100009],n,sum,raz;
long long nod(long long f,long long s)
{
    long long r;
    while(s!=0)
    {
        r=f%s;
        f=s;
        s=r;
    }
    return f;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];sum+=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        raz+=(i-1)*2*a[i];
        raz-=(n-i)*2*a[i];
    }
    long long fi=raz+sum,se=n;
    long long nd=nod(fi,se);
    fi/=nd;se/=nd;
    cout<<fi<<" "<<se<<endl;
}

