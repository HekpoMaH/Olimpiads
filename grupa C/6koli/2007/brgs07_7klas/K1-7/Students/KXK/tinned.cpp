#include<iostream>
#include<string>
using namespace std;
string a,b;
int k,m,n,nw;
void eql()
{
    int i;
    string r;
    if(m<n)
    {
        nw=n;
    for(i=m;i<n;i++)
    r+="0";
    
    r+=a;
    a=r;
    }
    if(n<m)
    {
        nw=m;
    for(i=n;i<m;i++)
    r+="0";
    
    r+=b;
    b=r;
    }
    return;
}
int main()
{
    cin>>a>>b>>k;
    string r="";
    int i,j;
    m=a.size();
    n=b.size();
    nw=m;
    if(m!=n) eql();
    int nu=0,r2;
    for(i=nw-1;i>=0;i--)
    {
        r2=nu+(int)a[i]-48+(int)b[i]-48;
        nu=r2/10;
        r2%=10;
        a[i]=(char)r2+48;
    }
    if(nu)
    {
        nw++;
        string x="";
        nu+=48;
        char ff=(char)nu;
        x+=ff;
        x+=a;
        a=x;
    }
    nu=0;
    for(i=nw-1;i>=0;i--)
    {
        r2=(int)a[i]-48;
        r2*=k;
        r2+=nu;
        nu=r2/10;
        r2%=10;
        a[i]=(char)r2+48;
    }
    if(nu) cout<<nu;
    cout<<a<<"\n";
    return 0;
}
