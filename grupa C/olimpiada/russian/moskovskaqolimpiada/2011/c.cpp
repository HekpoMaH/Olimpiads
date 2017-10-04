#include<iostream>
using namespace std;
struct point
{
    int x,y;
};
point a,b,c,d;
bool prov(point p1,point p2,point p3,point p4)
{
    if((p2.x-p1.x)*(p3.y-p4.y)-(p3.x-p4.x)*(p2.y-p1.y)==0&&(p4.x-p1.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p4.y-p1.y)==0)return true;
    //cout<<(p4.x-p1.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p4.y-p1.y)<<endl;
    return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    //cout<<prov(a,d,b,c)<<endl;
    if(prov(a,b,c,d)==true||prov(a,b,d,c)==true||prov(a,c,b,d)==true||prov(a,c,d,b)==true||prov(a,d,b,c)==true||prov(a,d,c,b)==true
       ||prov(b,a,c,d)==true||prov(b,a,d,c)==true||prov(b,c,a,d)==true||prov(b,c,d,a)==true||prov(b,d,a,c)==true||prov(b,d,c,a)==true
       ||prov(c,a,b,d)==true||prov(c,a,d,b)==true||prov(c,b,a,d)==true||prov(c,b,d,a)==true||prov(c,d,a,b)==true||prov(c,d,b,a)==true
       ||prov(d,a,b,c)==true||prov(d,a,c,b)==true||prov(d,b,a,c)==true||prov(d,b,c,a)==true||prov(d,c,a,b)==true||prov(d,c,b,a)==true)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
    return 0;
}
