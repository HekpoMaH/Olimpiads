#include<bits/stdc++.h>
using namespace std;
long long x,y,a,b;
long long nok;
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
    cin>>x>>y>>a>>b;
    nok=x*y/nod(x,y);
    long long s1,s2;
    s1=b/nok;
    s2=a/nok;
    if(a%nok==0)s2--;
    //cout<<nok<<endl;
    cout<<s1-s2<<endl;
}
