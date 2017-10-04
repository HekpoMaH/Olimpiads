#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;
const int inf=1e9;
const int MAX_N=10009;
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
vec lp;
bool cmp(vec f,vec s)
{
    vec u=vec(f-lp),v=vec(s-lp);
    if(cross(u,v)>0)return true;
    if(cross(u,v)<0)return false;
    if(u.len2()<v.len2())return true;
    return false;
}

int n;
vector<vec> obv;
vec p[MAX_N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;lp.y=inf;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;
        if(p[i].y<lp.y)lp=p[i];
        else if(p[i].y==lp.y) if(p[i].x<lp.x)lp=p[i];
    }
    //cout<<lp.x<<" "<<lp.y<<endl;//exit(0);
    sort(p+1,p+n+1,cmp);
    int idx;
    for(int i=1;i<=n;i++)
    {
        //p[i+n]=p[i];
        if(lp.x==p[i].x&&lp.y==p[i].y)idx=i;
    }
    ///exit(0);
    obv.push_back(p[idx]);
    vec AB,AC;
    for(int i=2;i<=n;i++)
    {
        AB=p[i]-obv[obv.size()-2];
        AC=p[i]-obv[obv.size()-1];
        while(obv.size()>2&&cross(AB,AC)<=0)
        {
            obv.pop_back();
            AB=p[i]-obv[obv.size()-2];
            AC=p[i]-obv[obv.size()-1];

        }
        obv.push_back(p[i]);
    }
    double s1=0;
    for(int i=2;i<obv.size();i++)
    {
        AB=obv[i]-obv[0];
        AC=obv[i-1]-obv[0];
        s1+=cross(AB,AC);
    }
    cout<<fabs(s1)/2.0<<endl;
}

