//mindmap
#include<bits/stdc++.h>
using namespace std;
struct vec
{
    double x,y;
    vec(){}
    vec(double _x,double _y){x=_x;y=_y;}
    vec operator+(vec b){return vec(x+b.x,y+b.y);}
    vec operator-(vec b){return vec(x-b.x,y-b.y);}
    vec operator*(double k){return vec(k*x,k*y);}
};
int n;
vec cr,x;
int main()
{
    cin>>n;
    double a,b,c;
    cr=vec(0,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        x=vec(a,b);
        x=x*c;
        cr=x+cr;
    }
    cr=cr*(-1);
    cout<<cr.x<<" "<<cr.y<<endl;
}
