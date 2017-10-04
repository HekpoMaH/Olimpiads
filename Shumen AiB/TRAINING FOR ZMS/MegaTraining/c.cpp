#include<iostream>
using namespace std;
int x[44],y[44],l;
long long ab,bc,cd,da;
void solve(int xa,int xb,int xc,int xd,int ya,int yb,int yc,int yd)
{//cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
    ab=(xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
    bc=(xb-xc)*(xb-xc)+(yc-yb)*(yc-yb);
    cd=(xc-xd)*(xc-xd)+(yc-yd)*(yc-yd);
    da=(xa-xd)*(xa-xd)+(ya-yd)*(ya-yd);
    //cout<<ab<<" "<<bc<<" "<<cd<<" "<<da<<endl;
    //cout<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<" "<<xc<<" "<<yc<<" "<<xd<<" "<<yd<<endl;
    if(ab==cd&&bc==da)cout<<"YES"<<endl,l=1;
    //else cout<<"NO"<<endl;
}
void solve1()
{
    l=0;
    for(int i=1;i<=4;i++)cin>>x[i]>>y[i];
    //cout<<"AA"<<x[1]<<" "<<y[1]<<endl;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=4;k++)
            {
                for(int k1=1;k1<=4;k1++)
                {
                    if(!(i==j||i==k||i==k1||j==k||j==k1||k==k1)&&l==0)solve(x[i],x[j],x[k],x[k1],y[i],y[j],y[k],y[k1]);
                }
            }
        }
    }if(l==0)cout<<"NO"<<endl;
}
int main()
{
    int t=1;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve1();
    }
}
