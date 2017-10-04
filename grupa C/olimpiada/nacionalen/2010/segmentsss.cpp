#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
    int pos;
    int kr;
    int pr;
    long long sum;
    long long cena;
};
bool cmp(point a,point b)
{
    if(a.pos<b.pos)return true;
    if(a.pos>b.pos)return false;
    if(a.kr<b.kr)return true;
    return false;
}
point a[200000];
int n,f,s,t;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>f>>s>>t;
        a[2*i].pos=f;a[2*i].kr=1;a[2*i].pr=t;
        a[2*i+1].pos=s;a[2*i+1].kr=-1;a[2*i+1].pr=-t;
    }
    n=2*n;
    sort(a,a+n,cmp);
    a[0].sum=a[0].pr;
    for(int i=1;i<n-1;i++)
    {
        a[i].sum=a[i-1].sum+a[i].pr;
    }
    int x0=a[0].pos;
    for(int i=1;i<n;i++)
    {
        if(a[i-1].pos!=a[i].pos)a[i-1].cena=a[i-1].sum*(a[i].pos-x0);
        x0=a[i].pos;
    }
    long long s=0,mx=0;
    for(int i=0;i<n-1;i++)if(a[i].pos!=a[i+1].pos)
    {
        s+=a[i].cena;
        if(s>mx)mx=s;
        if(s<0)s=0;
    }
    cout<<mx<<endl;
    return 0;
}