//mindmap
#include<bits/stdc++.h>
#define PI 3.14159265
using namespace std;
struct vec
{
    double x,y;
    vec(){}
    vec(double _x,double _y){x=_x;y=_y;}
    vec operator+(vec b){return vec(x+b.x,y+b.y);}
    vec operator-(vec b){return vec(x-b.x,y-b.y);}
    vec operator*(double k){return vec(k*x,k*y);}
    double len2(){return x*x+y*y;}
    vec rot(double alpha)
    {
        return vec(x*cos(alpha)-y*sin(alpha),x*sin(alpha)+y*cos(alpha));
    }
    double len(){return sqrt(this->len2());}
};
double dot(vec u,vec v)
{
    return u.x*v.x+u.y*v.y;
}
double cross(vec u,vec v)
{
    return u.x*v.y-v.x*u.y;
}
vec K,D;
double r;

int main()
{
    cin>>K.x>>K.y;
    cin>>D.x>>D.y;
    cin>>r;
    vec KD=D-K;
    //cout<<KD.x<<" "<<KD.y<<endl;
    //cout<<r<<" "<<KD.len2()<<endl;
    printf("%.2lf\n",(asin(r/KD.len())*(180.0/PI)));
    //cout<<asin(r/KD.len())*180.0/PI<<endl;
}


