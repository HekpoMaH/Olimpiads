#include<iostream>
#include<algorithm>
#define M 1000005
using namespace std;
long long n,q,m,a[M];
long long s[M],tot=0,res;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        tot+=s[i];
    }
    cin>>m;
    while(m--)
    {
        cin>>q;
        if(q==1)res=tot-s[n];
        else
        {
            long long tmp=n-1,t=1;
            for(res=0;tmp>=0;t*=q,tmp-=t)res+=s[tmp];
        }
        cout<<res;
        if(m) cout<<' ';
        else cout<<endl;
    }
    return 0;
}