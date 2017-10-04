#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
const int MAXN=555;
const int add=10001;
struct Point
{
    int x,y;
    int type,cost;
    double dp;
};
int n;
double sum;
double dp[2*MAXN];
int it[1001001];
int beg;
Point a[2*MAXN];
void read()
{
    int i,x1,x2,y,cost;
    scanf("%d",&n);
    scanf("%d%d%d%d",&a[0].x,&a[0].y,&a[2*n+1].x,&a[2*n+1].y);
    a[0].y+=add;
    a[2*n+1].y+=add;
    a[0].type=2;
    a[0].cost=0;
 
    a[n*2+1].cost=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&x1,&x2,&y,&cost);
        y+=add;
        a[i].x=x1;
        a[i].y=y;
        a[i].type=1;
        a[i].cost=cost;
 
        a[i+n].x=x2;
        a[i+n].y=y;
        a[i+n].type=3;
        a[i+n].cost=cost;
 
        sum+=double(cost);
    }
}
bool cmp(Point el1,Point el2)
{
    return el1.y>el2.y;
}
bool cmp2(Point el1,Point el2)
{
    el1.x-=a[beg].x;
    el1.y-=a[beg].y;
    el2.x-=a[beg].x;
    el2.y-=a[beg].y;
    if(el1.x*el2.y-el1.y*el2.x<0)return 1;
    if(el1.x*el2.y-el1.y*el2.x>0)return 0;
    if(el1.type<el2.type)return 1;
    if(el1.type>el2.type)return 0;
    if(el1.type==1)return el1.y<el2.y;
    return el1.y>el2.y;
}
double Distance(int i,int j)
{
    return sqrt(double((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)));
}
int Find(int k,int l,int r,int l1,int r1)
{
    /*if(l1>r||l>r1)return 0;
    if(l1<=l&&r<=r1)return it[k];
    return Find(k*2,l,(l+r)/2,l1,r1)+Find(k*2+1,(l+r)/2+1,r,l1,r1);*/
    int ans=0;
    //printf("%d %d ",l1,r1);
    while(1)
    {
        ans+=it[r1];
        r1-=r1&(-r1);
        if(r1==0)break;
    }
    /*l1--;
    while(1)
    {
        ans-=it[l1];
        l1-=l1&(-l1);
        if(l1==0)break;
    }*/
    return ans;
}
void Update(int k,int l,int r,int idx,int c)
{
    /*it[k]+=c;
    if(l==r)return;
    if(idx<=(l+r)/2)Update(k*2,l,(l+r)/2,idx,c);
    else Update(k*2+1,(l+r)/2+1,r,idx,c);*/
    while(idx<=2*add)
    {
        it[idx]+=c;
        idx+=idx&(-idx);
    }
}
void solve()
{
    int i,j;
    double curr,best;
    sort(a,a+(2*n+2),cmp);
    a[0].dp=sum;
    for(i=1;i<=3;i++)
    {
        beg=i;
        sort(a,a+i,cmp2);
        best=-1;
    //    for(j=0;j<i;j++)
    //    {
    //       cerr<<a[j].x<<" x "<<a[j].y<<"\n";
    //        //printf("!%d %d %lf %lf %lf %d\n",a[j].x,a[j].y,a[j].dp,distance(i,j),curr,it[1]);
    //    }
    //  cerr<<"==================================\n";
    //    continue;
        for(j=0;j<i;j++)
        {
            if(a[i].y==a[j].y)continue;
            curr=a[j].dp;
            cerr<<"a["<<j<<"]="<<a[j].dp<<"\n";
            cerr<<curr<<"\n";
            curr+=Distance(i,j);
            cerr<<curr<<"\n";
            if(a[j].y-a[i].y>1)curr-=double(Find(1,1,2*add,a[i].y+1,a[j].y-1));
            cerr<<(Find(1,1,2*add,a[i].y+1,a[j].y-1))<<" ";cerr<<curr<<"\n";
            if(best==-1||curr<best)best=curr;
            if(a[j].type==1)Update(1,1,2*add,a[j].y,a[j].cost);
            if(a[j].type==3)Update(1,1,2*add,a[j].y,-1*a[j].cost);
            //printf("!%d %d %lf %lf %lf %d\n",a[j].x,a[j].y,a[j].dp,distance(i,j),curr,it[1]);
        }
        a[i].dp=best-a[i].cost;
        printf("%d %d %d %lf\n",a[i].x,a[i].y,i,a[i].dp);
      cerr<<"==================================\n";
    }
    printf("%.4lf\n",a[i-1].dp);
}
int main()
{
    read();
    solve();
}
