#include<iostream>
using namespace std;
int main()
{
    int xa1,xa2,ya1,ya2,xb1,xb2,yb1,yb2;
    int maxx,maxy,minx,miny;
    cin>>xa1>>ya1>>xa2>>ya2>>xb1>>yb1>>xb2>>yb2;
    maxx=xa1;
    if(xa2>maxx)maxx=xa2;
    if(xb1>maxx)maxx=xb1;
    if(xb2>maxx)maxx=xb2;
    minx=xa1;
    if(xa2<minx)minx=xa2;
    if(xb1<minx)minx=xb1;
    if(xb2<minx)minx=xb2;
    maxy=ya1;
    if(ya2>maxy)maxy=ya2;
    if(yb1>maxy)maxy=yb1;
    if(yb2>maxy)maxy=yb2;
    miny=ya1;
    if(ya2<miny)miny=ya2;
    if(yb1<miny)miny=yb1;
    if(yb2<miny)miny=yb2;
    for(int i=minx;i<=maxx;i++)
    {
            for(int j=miny;j<=maxy;j++)
            {
                    if((i>=xa1&&i<=xa2&&j>=ya1&&j<=ya2)||(i>=xb1&&i<=xb2&&j>=yb1&&j<=yb2))
                    {
                                 cout<<i<<" "<<j<<endl;
                    }
            }
    }
    system("pause");
    return 0;
}
