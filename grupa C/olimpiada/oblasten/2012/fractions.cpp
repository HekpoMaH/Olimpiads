#include<iostream>
using namespace std;
int nod(long long a,long long b)
{
    long long r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void sbdr(long long &t4,long long &tz,long long v4,long long vz)
{
    //nok na dvata znamenatelq
    long long nok=(tz*vz)/nod(tz,vz);
    //umn 4isl
    t4*=nok/tz;
    v4*=nok/vz;
    t4+=v4;
    tz=nok;
    long long nd=nod(t4,tz);
    t4/=nd;tz/=nd;
}
long long n,ch,zn=1,cela;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)sbdr(ch,zn,1,i);
    //cout<<ch<<" "<<zn<<endl;
    cela=ch/zn;ch%=zn;
    long long nf=nod(ch,zn);
    ch/=nf;zn/=nf;
    cout<<cela<<" "<<ch<<" "<<zn<<endl;
    return 0;
}
