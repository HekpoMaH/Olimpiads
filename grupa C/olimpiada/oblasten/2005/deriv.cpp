#include<iostream>
using namespace std;
long long mem[12][1024];
long long p,k;
long long findd(long long x)
{
    for(int i=2;i/2<=x;i++)
    {
        if(x%i==0)return i;
    }
    return 1;
}
bool prime(long long x)
{
    for(int i=2;i*i<=x;i++)if(x%i==0)return false;
    return true;
}
long long proizvodna(long long k,long long p)
{
    cout<<k<<" "<<p<<endl;
    //if(mem[k][p]!=-1)return mem[k][p];
    if(prime(p)==true)
    {
        //mem[k][p]=1;
        cout<<"here"<<endl;
        return 1;
    }
    if(p==1)
    {
        //mem[k][p]=0;
        cout<<"here"<<endl;
        return 0;
    }
    long long a=findd(p),b=p/a;
    long long x=proizvodna(k-1,a)*b,y=a*proizvodna(k-1,b);
    cout<<"x="<<x<<" "<<y<<endl;
    return x+y;
}
int main()
{
    //for(int i=1;i<=11;i++)
    //for(int j=1;j<=1023;j++)mem[i][j]=-1;
    cin>>p>>k;
    //cout<<prime(2)<<endl;
    cout<<proizvodna(k,p)<<endl;
    return 0;
}
