#include<iostream>
using namespace std;
int x,y,z,xx,yy,zz,a1,a2,a3,a4,a5,a6,sum;
int main()
{
    cin>>x>>y>>z>>xx>>yy>>zz>>a1>>a2>>a3>>a4>>a5>>a6;
    if(y<0)sum+=a1;
    if(y>yy)sum+=a2;
    if(z<0)sum+=a3;
    if(z>zz)sum+=a4;
    if(x<0)sum+=a5;
    if(x>xx)sum+=a6;
    cout<<sum<<endl;
    return 0;
}
