#include<bits/stdc++.h>
using namespace std;
struct pnt
{
    long long x;
    long long y;
};

bool cmp(pnt a,pnt b)
{
    if(abs(a.x)!=abs(b.x))return abs(a.x)<abs(b.x);
    else return abs(a.y)<abs(b.y);
}
pnt a[100000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,xcor,ycor,br;
    cin>>n;
    br=n*6;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        if(a[i].x==0 || a[i].y==0)br-=2;
    }
    cout<<br<<"\n";
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        xcor=a[i].x;
        ycor=a[i].y;
        if(xcor!=0)
        {
            cout<<1<<" "<<abs(xcor)<<" ";if(xcor>0){cout<<"R";}
            else cout<<"L";cout<<"\n";
        }
        if(ycor!=0)
        {
            cout<<1<<" "<<abs(ycor)<<" ";if(ycor>0){cout<<"U";}
            else cout<<"D";cout<<"\n";
        }
        cout<<2<<"\n";
        if(xcor!=0)
        {
            cout<<1<<" "<<abs(xcor)<<" ";if(xcor<0){cout<<"R";}
            else cout<<"L";cout<<"\n";
        }
        if(ycor!=0)
        {
            cout<<1<<" "<<abs(ycor)<<" ";if(ycor<0){cout<<"U";}
            else cout<<"D";cout<<"\n";
        }
        cout<<3<<"\n";
    }
    return 0;
}
