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
int n,m;
vec P[1009];
int main()
{
    cin>>n;
    double s1=0,s2=0,a,b;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        P[i]=vec(a,b);
    }
    for(int i=2;i<=n;i++)
    {
        vec AB;
        AB.x=P[i].x-P[1].x;AB.y=P[i].y-P[1].y;
        vec AC;
        AC.x=P[i-1].x-P[1].x;AC.y=P[i-1].y-P[1].y;
        s1+=cross(AB,AC);
    }
    s1=fabs(s1);
    s1/=2.0;
    cin>>n;
    s2=0;//cout<<s1<<" "<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        P[i]=vec(a,b);
    }
    //for(int i=1;i<=n;i++)cout<<P[i].x<<" "<<P[i].y<<endl;
    for(int i=2;i<=n;i++)
    {
        vec AB;
        AB.x=P[i].x-P[1].x;AB.y=P[i].y-P[1].y;
        vec AC;
        AC.x=P[i-1].x-P[1].x;AC.y=P[i-1].y-P[1].y;
        s2+=cross(AB,AC);
    }
    s2/=2.0;
    s2=fabs(s2);
    //cout<<s1<<" "<<s2<<endl;
    cout<<fabs(s1-s2)<<endl;
}
