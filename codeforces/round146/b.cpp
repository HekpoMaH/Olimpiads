#include<iostream>
#include<cstring>
using namespace std;
long long mod=1073741824;
long long d[1000006],a,b,c,g;
long long dd(long long f)
{
    if(d[f]>0)return d[f];
    long long s=1,d=2,br;
    while(f!=1)
    {
        br=0;
        while(f%d==0)
        {
            f/=d;br++;
        }
        s*=(br+1);d++;
    }
    return s;
}
int main()
{
    cin>>a>>b>>c;
    memset(d,-1,sizeof(d));
    //cout<<d[9]<<endl;
    long long sum=0;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            for(int k=1;k<=c;k++)
            {
                //cout<<i<<" "<<j<<" "<<k<<endl;
                g=dd(i*j*k);
                d[i*j*k]=g;
                sum=(sum+g)%mod;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
