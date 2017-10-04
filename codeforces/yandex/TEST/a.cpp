#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<map>
using namespace std;
double n,div=2,x1,x2,x3,yy1,y2,y3,s,r;
int mxr;double sa,sb,sc;
map<double,int> mp;
int main()
{
    ifstream fin("circles.in");
    ofstream fout("circles.out");
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x1>>yy1>>x2>>y2>>x3>>y3;
        double a=yy1-y2,b=x2-x1,c=x1*y2-x2*yy1;
        s=a*x3+b*y3+c;
        s/=2;
        //cout<<fabs((x1-x2)*(x1-x2)-(yy1-y2)*(yy1-y2))<<" "<<fabs((x1-x3)*(x1-x3)-(yy1-y3)*(yy1-y3))<<" "<<fabs((x3-x2)*(x3-x2)-(y3-y2)*(y3-y2))<<endl;
        sa=fabs((x1-x2)*(x1-x2)+(yy1-y2)*(yy1-y2));
        sb=fabs((x1-x3)*(x1-x3)+(yy1-y3)*(yy1-y3));
        sc=fabs((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        if(s<0)s=-s;
        r=(double)(sa*sb*sc/16*s);
        //cout<<r<<" "<<sa<<" "<<sb<<" "<<sc<<" "<<s<<endl;
        mp[r]++;
        if(mp[r]>mxr)mxr=mp[r];
    }
    fout<<mxr<<endl;
}


