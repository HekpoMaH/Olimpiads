#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long lli;
lli w,m,k,som;
lli ans,x,zp;
lli csom(lli xx)
{
    lli re=0;
    while(xx!=0)re++,xx/=10;
    return re;
}
lli na10(lli xx)
{
    lli re=1;
    for(int i=1;i<=xx;i++)re*=10;//,cout<<"re="<<re<<endl;
    return re;
}
int main()
{
    cin>>w>>m>>k;
    som=csom(m);
    lli last=m;
    //cout<<som<<endl;
    //cout<<na10(1)<<" "
    for(int i=som;;i++)
    {
        x=na10(i);
        //cout<<"x="<<x<<" last="<<last<<" i="<<i<<" na10 "<<na10(i)<<endl;
        if((x-last)*i*k<=w)
        {
            //cout<<"za golemina "<<i<<" stigat. 4islata sa to4no : "<<x-last<<" i cenata za tqhnoto slagane e "<<(lli)(x-last)*i*k<<endl;
            w-=(x-last)*i*k;
            ans+=(x-last);
            last=x;
            continue;
        }
        //cout<<"za golemina "<<i<<" ne stigat. 4islata sa to4no : "<<x-last<<" i cenata za tqhnoto slagane e "<<(x-last)*i*k<<endl;
        //cout<<"imame cena "<<w<<" "<<"i 4islata ot toq vid struvat "<<(i*k)<<" zatova mojem da slojim"<<w/(i*k)<<endl;
        ans+=w/(i*k);
        break;
    }
    cout<<ans<<endl;
}
