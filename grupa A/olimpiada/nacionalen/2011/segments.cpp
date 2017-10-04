#include<iostream>
using namespace std;
int n;
struct po
{
    int x,y;
};
po c[200],d[200];
int cp(po p0,po p1,po p2)
{
    int dx1=p1.x-p0.x;
    int dx2=p2.x-p0.x;
    int dy1=p1.y-p0.y;
    int dy2=p2.y-p0.y;
    return dx1*dy2-dx2*dy1;
}
bool check(po a,po b,po c,po d)
{
    int e1=cp(a,b,c);
    int e2=cp(a,b,d);
    if(e1==0)return true;
    if(e2==0)return true;
    if(((e1<0)&&(e2>0))||((e1>0)&&(e2<0)))return true;
    return false;
}
int numsec(po a,po b)
{
    int num=0;
    if(a.x==b.x&&(a.y=b.y))return num;
    for(int i=1;i<=n;i++)
    {
        if(check(a,b,c[i],d[i]))num++;
    }
    return num;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i].x>>c[i].y>>d[i].x>>d[i].y;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int br=0;
            br=numsec(c[i],c[j]);
            if(br>ans)ans=br;
            br=numsec(c[i],d[j]);
            if(br>ans)ans=br;
            br=numsec(d[i],c[j]);
            if(br>ans)ans=br;
            br=numsec(d[i],d[j]);
            if(br>ans)ans=br;
        }
    }
    if(ans==0)
    {
        ans=1;
        if(n>1)ans=2;
    }
    cout<<ans<<endl;
}
