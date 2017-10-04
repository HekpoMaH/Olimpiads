#include<iostream>
#include<cmath>
using namespace std;
int m,n;
int x[5], y[5];
int ds(int i1, int i2)
{
    return (x[i1]-x[i2])*(x[i1]-x[i2])+(y[i1]-y[i2])*(y[i1]-y[i2]);
}
int s()
{
    return (2*n*m-y[1]*x[2]-(m-x[2])*y[3]-(n-y[3])*(m-x[4])-x[4]*(n-y[1]))/2;
}
int main()
{
    cin>>m>>n;
    int rmin=n*m, rmax=0,dd1,dd2;
    for(int i1=0;i1<=n;i1++)
    for(int i2=0;i2<=m;i2++)
    {
        x[1]=0;y[1]=i1;
        x[2]=i2;y[2]=0;
        x[3]=m;y[3]=n-y[1];
        x[4]=m-x[2];y[4]=n;
        dd1=ds(1,3);
        dd2=ds(2,4);
        if(dd1==dd2)
        {
            int ss=s();
            if(ss!=0)
            if(ss<rmin)rmin=ss;
        if(ss!=m*n)
        if(ss>rmax)rmax=ss;
        }

    }
    if(rmin>rmax)rmin=0;
    cout<<rmin<<".0 "<<rmax<<".0"<<endl;
    return 0;
}
