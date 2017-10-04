#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
    int x,y;
};
point a[15];
int n;
int ok[15][15],p[15];
int dir(point o,point t,point tr)
{
    int a1=t.x-o.x,a2=t.y-o.y;
    int b1=tr.x-o.x,b2=tr.y-o.y;
    int p=a1*b2,q=a2*b1;
    if(p>q)return 1;
    if(p<q)return -1;
    return 0;
}
bool isok(int i,int j)
{
    point xx=a[i],yy=a[j];
    bool lef=false,righ=false;
    for(int k=0;k<n;k++)
    {
        if(k!=i&&k!=j)
        {
            int s=dir(xx,yy,a[k]);
            if(s==0)return false;
            if(s>0){lef=true;if(righ)return false;}
            if(s<0){righ=true;if(lef)return false;}
        }
    }
    return true;
}
bool conv()
{
    for(int i=0;i<n;i++)
    {
        if(!ok[p[i]][p[(i+1)%n]])return false;
    }
    return true;
}
double area()
{
    double s=0;
    for(int i=1;i<n;i++)
    {
        s+=0.5*(a[p[i]].x-a[p[i-1]].x)*(a[p[i]].y+a[p[i-1]].y);
    }
    s+=0.5*(a[p[0]].x-a[p[n-1]].x)*(a[p[0]].y+a[p[n-1]].y);
    if(s<0)s=-s;
    return s;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y;
    int good=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(isok(i,j))
            {
                good++;
                ok[i][j]=ok[j][i]=1;
            }
        }
    }
    if(good!=n){cout<<0<<endl;return 0;}
    for(int i=0;i<n;i++)
    {
        p[i]=i;
    }
    bool co=conv();
    while(!co&&next_permutation(p+1,p+n))
    {
        co=conv();
    }
    if(co==true)cout<<area()<<endl;
    else cout<<0<<endl;
}
