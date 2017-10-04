#include<iostream>
#include<cmath>
using namespace std;
typedef long long lli;
long long x,y,n;
lli a=0,b=1;
int main()
{
    cin>>x>>y>>n;//bay=n;
    for(int i=1;i<=n;i++)
    {
       lli diff=abs(x*i*b-a*i*y);
       lli temp1=x*i/y;
       lli temp2=temp1+1;
       lli tdi=abs(temp1*b*y-x*i*b);
       lli tdi2=abs(temp2*b*y-x*i*b);
       if(tdi<diff)diff=tdi,a=temp1,b=i;
       if(tdi2<diff)diff=tdi2,a=temp2,b=i;
    }
    cout<<a<<"/"<<b<<endl;
}
