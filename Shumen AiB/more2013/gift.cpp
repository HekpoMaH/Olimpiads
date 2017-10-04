#include<bits/stdc++.h>
using namespace std;
long long n;
long long a,b,c;
long long mx;
int main()
{
    cin>>n;
    /*for(int i=1;;i++)
    {
        if(3*i*i>n/2){a=b=c=i;break;}
    }*/
    //cout<<a<<" "<<b<<" "<<c<<endl;
    long long qrn=sqrt(n/6),qqr=sqrt(sqrt(n));
    for(long long i=max(1LL,qrn-qqr);i<=qrn+qqr;i++)
    {
        for(long long j=max(1LL,qrn-qqr);j<=qrn+qqr;j++)
        {
            long long k=(n-2*i*j)/(2*(i+j));
            //cout<<k<<" "<<i<<" "<<j<<endl;
            if(i*j*k>mx)
            {
                    a=i;b=j;c=k;
                mx=i*j*k;
            }
        }
    }
    cout<<mx<<endl;
    cout<<a<<" "<<b<<" "<<c<<endl;
}
