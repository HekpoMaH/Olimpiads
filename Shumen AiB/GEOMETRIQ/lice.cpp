#include<bits/stdc++.h>
using namespace std;
struct vec
{
    double x,y;
    void read(){scanf("%lf%lf",&x,&y);}
    vec(){};
    vec(double _x,double _y)
    {
        x=_x;y=_y;
    }
    vec operator+(vec a){return vec(x+a.x,y+a.y);}
    vec operator-(vec a){return vec(x-a.x,y-a.y);}
    double len2(){return x*x+y*y;}
    double len(){return sqrt(x*x+y*y);}
};
double dot(vec f,vec s){return f.x*s.x+f.y*s.y;}
double cross(vec f,vec s){return f.x*s.y-s.x*f.y;}
vec A,B,C;
int main()
{
    A.read(),B.read(),C.read();
    //cout<<"EEE"<<endl;
    vec ab=B-A,ba=A-B,bc=C-B,ac=C-A;
    //cout<<ba.len()<<" "<<ab.len()<<endl;
    double bc1len=fabs(dot(ba,bc))/ba.len();
    double h=(fabs(cross(ab,ac)))/ab.len();
    //cout<<"h="<<h<<endl;
    printf("%.3lf\n",(h*bc1len)/2.0);
}
