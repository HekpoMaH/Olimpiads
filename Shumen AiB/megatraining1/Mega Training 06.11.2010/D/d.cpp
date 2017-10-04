#include<bits/stdc++.h>
using namespace std;
long long p[1000],pn,n,k,b[1009];
void findprimes(int k)
{
    p[1]=2;
    int br=1;
    int i=3,j;
    bool f;
    while(i<=k)
    {
        j=1;
        f=true;
        while(p[j]*p[j]<=i)
        {
            if(i%p[j]==0)
            {
                f=false;
                break;
            }
            j++;
        }
        if(f==true)
        {
            pn++;
            p[pn]=i;
        }
        i+=2;
    }
}
long long find(long long m)
{
    long long r;
    r=0;
    int n1=n;
    while(n>0)
    {
        r+=n/m;
        n/=m;
    }n=n1;
    return r;
}
void findz()
{
    for(int i=1;i<=pn;i++)
    {
        b[i]=find(p[i]);
    }
    long long mn=1000000000000LL;
    for(int j=1;j<=pn;j++)
    {
        long long br=0;
        while(k%p[j]==0)k/=p[j],br++;
        //cout<<b[j]/br;
        //if(br>0)
        //long long x;
        if(br>0)
        {long long x=b[j]/br;
            mn=min(mn,x);
        }
    }
    cout<<mn<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        findprimes(k);
        findz();
    }
}
