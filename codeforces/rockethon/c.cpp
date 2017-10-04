#include<bits/stdc++.h>
using namespace std;
int n,k;
struct kulturist// za razlika ot 4onev ne gi pi6a "tuhla"
{
    int p,e,bit;
};
kulturist a[200009];
long long ans;
bool cmp2(kulturist edno,kulturist dve)
{
    if(edno.p>dve.p)return true;
    if(edno.p<dve.p)return false;
    //if(edno.bit>dve.bit)return true;
    if(edno.p==dve.p)
    {
        if(edno.e==-100)
        {
            if(dve.bit==1)return true;
            return false;
        }
        if(dve.e==-100)
        {
            if(edno.bit==1)return false;
            return true;
        }
        return edno.bit<dve.bit;
    }
    return false;
}
bool chek(long long x)
{
    int uk1;
    for(int i=1;i<=n+1;i++){if(a[i].e==-100)a[i].p=0,uk1=i;a[i].bit=0;}
    cout<<x<<endl;
    //a[n+1].p=0;a[n+1].e=-2;
    for(int i=1;i<=n+1;i++)
    {
        if(a[i].e!=-100){if(a[i].e<=x)a[i].bit=1,a[uk1].p++,x-=a[i].e;
        else break;
        }cout<<i<<"->"<<a[uk1].p<<" "<<x<<endl;
    }

    sort(a+1,a+n+2,cmp2);
    for(int i=1;i<=n+1;i++)
    {
        cout<<a[i].p<<" "<<a[i].bit<<" "<<a[i].e<<endl;
    }
    //if(xib==11)exit(0);
    for(int i=1;i<=k;i++)
    {
        if(a[i].e==-100)return true;
    }
    return false;
}
bool cmp(kulturist edno,kulturist dve)
{
    if(edno.e<dve.e)return true;
    if(edno.e>dve.e)return false;
    if(edno.p<dve.p)return true;
    return false;
}
int main()
{
    //ran[209]=1;
    //cout<<"E"<<" "<<ran[209]<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long mw=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i].p>>a[i].e,mw+=a[i].e;
    a[n+1].p=0;a[n+1].e=-100;
    long long l=0,r=mw,mid;
    ans=mw+1;
    while(l<=r)
    {
        mid=(l+r)/2;
        sort(a+1,a+n+1,cmp);
        cout<<mid<<" -- "<<endl;//sort(a+1,a+n+1,cmp);
        if(chek(mid)){ans=mid;r=mid-1;}
        else l=mid+1;
    }
    if(ans==mw+1)cout<<-1<<endl;
    else cout<<ans<<endl;
}
