#include<iostream>
#include<cmath>
#define PI 3.14159265
using namespace std;
typedef long long lli;
long long a,b,n;
lli mn1=1,mn2=1;
long long nod(long long  x,long long y)
{
    long long r;
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{
    cin>>a>>b>>n;
    cout<<(double)(a*b-(double)(a*a*sin(2*n*PI/180.0)/8))<<endl;
}
