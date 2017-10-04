#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long Int;

const double PI=4.0*atan(1.0);

double ToRad(double deg)
{
    return deg*PI/180.0;
}

double x[5],y[5];
Int cx[5],cy[5];
double dasin=sin(ToRad(0.0001)),dacos=cos(ToRad(0.0001));

void Rotate()
{
    Int i;
    double newx,newy;
    
    for (i=1;i<=4;i++)
    {
        newx=x[i]*dacos - y[i]*dasin;
        newy=x[i]*dasin + y[i]*dacos;
        
        x[i]=newx;
        y[i]=newy;
    }
    
    return;
}

double Projection()
{
    double themin,themax;
    double p;
    themin=x[1];
    themax=x[1];
    
    if (x[2]<themin)
    themin=x[2];
    if (x[2]>themax)
    themax=x[2];

    if (x[3]<themin)
    themin=x[3];
    if (x[3]>themax)
    themax=x[3];

    if (x[4]<themin)
    themin=x[4];
    if (x[4]>themax)
    themax=x[4];
    
    p=themax-themin;
    
    themin=y[1];
    themax=y[1];
    if (y[2]<themin)
    themin=y[2];
    if (y[2]>themax)
    themax=y[2];

    if (y[3]<themin)
    themin=y[3];
    if (y[3]>themax)
    themax=y[3];

    if (y[4]<themin)
    themin=y[4];
    if (y[4]>themax)
    themax=y[4];
    
    if (themax-themin>p)
    {
        p=themax-themin;
    }
    
    return p;
}

int main()
{
    Int i;
    double minproj;
    double proj;
    Int minx=999999999,miny=999999999;
    
    for (i=1;i<=4;i++)
    {
        scanf("%lld %lld",&cx[i],&cy[i]);
        if (cx[i]<minx)
        minx=cx[i];
        if (cy[i]<miny)
        miny=cy[i];
    }
    for (i=1;i<=4;i++)
    {
        cx[i]=cx[i]-minx;
        cy[i]=cy[i]-miny;
        
        x[i]=(double)cx[i];
        y[i]=(double)cy[i];
    }
    
    minproj=Projection();
    
    for (i=1;i<=900000;i++)
    {
        Rotate();
        proj=Projection();
        
        if (proj<minproj)
        {
            minproj=proj;
        }
    }
    
    printf("%.3f\n",minproj);
    
    return 0;
}
