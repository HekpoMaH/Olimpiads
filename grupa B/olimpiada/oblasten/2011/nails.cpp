#include<iostream>
using namespace std;
struct point
{
    int x,y;
};
point a[1024],b[1024];
int n;
bool adj[1023][1023];
bool vis[1023];
int compsize;
int direction(point A,point B,point C)
{
    int a1=B.x-A.x;int a2=B.y-A.y;
    int b1=C.x-A.x;int b2=C.y-A.y;
    int p=a1*b2,q=a2*b1;
    if(p>q)return 1;
    if(p<q)return -1;
    return 0;
}
bool onsegment(point A,point B,point C)
{
    return min(A.x,B.x)<=C.x&&C.x<=max(A.x,B.x)&&min(A.y,B.y)<=C.y&&C.y<=max(A.y,B.y);
}
bool intersect(point A,point B,point C,point D)
{
    int d1=direction(A,B,C);
    int d2=direction(A,B,D);
    int d3=direction(C,D,A);
    int d4=direction(C,D,B);
    if(d1*d2<0&&d3*d4<0)return true;
    if(d1==0&&onsegment(A,B,C))return true;
    if(d2==0&&onsegment(A,B,D))return true;
    if(d3==0&&onsegment(C,D,A))return true;
    if(d4==0&&onsegment(C,D,B))return true;
    return false;
}
void dfs(int i)
{
    compsize++;
    //cout<<"AA"<<endl;
    vis[i]=true;
    for(int j=0;j<n;j++)
    {
        if(adj[i][j]&&!vis[j])dfs(j);
    }
}
int main()
{
    n=0;
    cin>>a[n].x>>a[n].y>>b[n].x>>b[n].y;
    while(cin.good())
    {
        n++,cin>>a[n].x>>a[n].y>>b[n].x>>b[n].y;
    }
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)adj[i][j]=adj[j][i]=intersect(a[i],b[i],a[j],b[j]);
    //compsize=0;
    dfs(n-1);
    cout<<n-compsize<<endl;
}
