#include<iostream>
using namespace std;
int main()
{
    int i,a,b,a2,b2,l=0;
    cin>>a>>b>>a2>>b2;
    if(a&&a2&&b==0)b=a2/(a*a);
    if(b&&b2&&a==0)a=b2/(b*b);
    if(a!=0&&b!=0){a2=(a*a)*b;b2=(b*b)*a;}
    if(a==0&&b==0&&b2)//da ne se barkam 1
    for(i=-1000;i<b2;i++)
    {
    for(int j=-1000;j<b2;j++)
    {
    if(j*j*i==b2){a=i;b=j;l=1;break;}
    }
    if(l==1)break;
    }
    if(a!=0&&b!=0&&a2==0)a2=(a*a)*b;
    if(a!=0&&b!=0&&b2==0)b2=(b*b)*a;
    if(a==0&&b==0&&a2)//da ne se barkam 2
    for(i=-1000;i<a2;i++)
    {
    for(int j=-1000;j<a2;j++)
    {
    if(j*j*i==a2){a=j;b=i;l=1;break;}
    }
    if(l==1)break;
    }
    if(b==0&&a&&b2)b=b2/a;
    for(i=-1000;i<b/2;i++)
    if(i*i==b){b=i;break;}
    if(a&&b==0&&a2==0&&b2==0)b=-1000;
    if(a!=0&&b!=0&&a2==0)a2=(a*a)*b;
    if(a!=0&&b!=0&&b2==0)b2=(b*b)*a;
    if(a&&b==0&&a2==0&&b2==0)b=-1000;
    if(b&&b2&&a==0)a=b2/(b*b);
    cout<<a<<' '<<b<<' '<<a2<<' '<<b2<<endl;
    return 0;
}
