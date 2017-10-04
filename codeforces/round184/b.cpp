#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;
long long x,y,p,q,n,tt;
long long a[100];
long long nod(long long a,long long b)
{
    long long r;
    while(b!=0)
    {
        r=a%b;a=b;b=r;
    }
    return a;
}
int main()
{
    cin>>p>>q;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    x=1;y=a[n];
    for(int i=n-1;i>=1;i--)
    {
        x+=a[i]*y;
        swap(x,y);
        tt=nod(x,y);
        x/=tt;y/=tt;
        //cout<<a[i]<<" "<<x<<" "<<y<<endl;
    }
    swap(x,y);
    long long nd=nod(x,y);
    x/=nd;y/=nd;
    nd=nod(p,q);p/=nd;q/=nd;
    if(p==x&&q==y)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

