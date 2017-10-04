#include<bits/stdc++.h>
#include<queue>
using namespace std;
int a[100009];
int fp,ans[100009];
int n,m,k;
int dasprali;

struct cho
{
    int a,b,in;
    bool st;
    bool operator<(const cho &x)const
    {
        return a<x.a;
    }
};
struct cho2
{
    int a,b,in;
    bool st;
    bool operator<(const cho2 &x)const
    {
        if(b==x.b)return st<x.st;
        return b>x.b;
    }
};
cho p[100009];
cho2 p2[100009];

int cmp(cho x,cho y)
{
    if(x.st!=y.st)return x.st>y.st;
    return x.b>y.b;
}
void decin()
{
    priority_queue<cho> pq;
    int i=m,br,j=1;
    sort(p+1,p+n+1,cmp);
    cho gat;

    while(i>0)
    {
        for(j;j<=n;j++)
        {
            if(p[j].b<i||p[j].st==0)break;
            //if(p[j].st==0)cout<<"EE"<<endl;
            gat.a=p[j].a;
            gat.in=j;
            gat.st=1;
            pq.push(gat);
        }
        br=0;
        //cout<<"enter"<<endl;
        while(br<k&&!pq.empty())
        {

            gat=pq.top();
            pq.pop();
            if(gat.a>i){cout<<0<<endl;exit(0);}
            br++;
            p[gat.in].b=i;
        }
        //cout<<"exit"<<endl;
        i--;
    }
    if(!pq.empty())
    {
        cout<<0<<endl;
        exit(0);
    }
}
int cmp2(cho x,cho y)
{
    return x.a<y.a;
}
void solveitmotherfucker()
{
    sort(p+1,p+n+1,cmp2);
    cho2 gat;
    int i,j=1,br=0;
    priority_queue<cho2> pq2;
    for(i=1;i<=m;i++)
    {
        br=0;
        for(;j<=n;j++)
        {
            if(p[j].a>i)break;
            if(p[j].a==i)
            {
                gat.a=p[j].a;
                gat.b=p[j].b;
                gat.in=p[j].in;
                gat.st=p[j].st;
                pq2.push(gat);
            }
        }
        while(!pq2.empty()&&br<k)
        {
            gat=pq2.top();
            pq2.pop();
            if(gat.b<i)continue;
            ans[gat.in]=i;
            br++;
        }
    }
    int broq4=0;
    for(i=1;i<=n;i++)if(ans[i]!=0)broq4++;
    printf("%d\n",broq4);
    for(i=1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    clock_t t;
    t=clock();
    int i;
    for(i=1;i<=m;i++)a[i]=k;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].st);
        p[i].in=i;
    }
    decin();

    for(i=1;i<=n;i++)
    {
        p2[i].a=p[i].a;
        p2[i].b=p[i].b;
        p2[i].st=p[i].st;
        p2[i].in=p[i].in;
    }
    //cout<<"--------------------------------__"<<endl;
    solveitmotherfucker();
    t=clock()-t;
    //cout<<"IT WAS "<<t/CLOCKS_PER_SEC<<endl;
}
