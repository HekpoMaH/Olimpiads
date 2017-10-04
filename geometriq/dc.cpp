//mindmap
#include<bits/stdc++.h>
using namespace std;
struct vec
{
    double x,y,dist0;
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
double cmp(vec f,vec s)
{
    return f.dist0<s.dist0;
}
int n,m;
vec P[1009];
int main()
{
    cin>>n;
    double s1=0,s2=0,a,b;unsigned long long best=(unsigned long long)10000000000000000;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        P[i]=vec(a,b);
        P[i].dist0=P[i].len2();
    }
    //sort(P+1,P+n+1,cmp);
    //for(int i=0)
    for(int i=1;i<=n;i++)
    {
        vec AB;
        for(int j=1;j<=n;j++)
        {
            if(j<1||j>n)continue;
            if(i==j)continue;
            AB=P[i]-P[j];
            if((P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y)<best)
            best=(P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y);
        }
    }
    printf("%.2lf\n",sqrt(best));
}

