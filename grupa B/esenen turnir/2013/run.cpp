#include<bits/stdc++.h>
using namespace std;
struct heapel
{
    double k;
    int ch,zn;
    int a,b;
    bool operator <(const heapel &x)const
    {
        //ch/zn>x.ch/x.zn -> ch*h.zn>zn*x.ch
        return k>x.k;
    }
};
struct runerel
{
    double s;
    int s1,s2;
    int d,p;
};
int n,l;
priority_queue<heapel> pq;
runerel r[500009];
int nod(int a,int b)
{  int r;
   if(a<b) {r=a;a=b;b=r;}
   while((r=a%b)!=0) {a=b;b=r;}
   return b;
}
void eliminate()
{
    int aa=pq.top().a,bb=pq.top().b,w;
    heapel he;
    pq.pop();
    if(r[aa].p!=0)
    {
        cout<<bb<<"\n";
        r[aa].p=r[bb].p;
        r[bb].p=0;

        if(aa!=r[aa].p&&r[aa].s>r[r[aa].p].s)
        {
            bb=r[aa].p;w=r[bb].d;
            if(aa>bb)w+=l;
            he.k=(w-r[aa].d)/(r[aa].s-r[bb].s);
            /*he.ch+=100*(w-r[aa].d);he.zn=(r[aa].s-r[bb].s);
            int nd=nod(he.ch,he.zn);
            he.ch/=nd;he.zn/=nd;*/
            he.a=aa;he.b=bb;

            pq.push(he);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l;
    heapel he;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i].d>>r[i].s;
        //r[i].s*=100;
        r[i].p=i+1;
    }
    r[n].p=1;r[n+1].d=l+r[1].d;r[n+1].s=r[1].s;
    for(int i=1;i<=n;i++)
    {
        if(r[i].s>r[i+1].s)
        {
            he.k=(r[i+1].d-r[i].d)/(r[i].s-r[i+1].s);
            /*he.ch=100*(r[i+1].d-r[i].d);he.zn=(r[i].s-r[i+1].s);
            int nd=nod(he.ch,he.zn);
            he.ch/=nd;he.zn/=nd;*/
            he.a=i;
            he.b=i+1;
            if(i==n)he.b=1;
            pq.push(he);
        }
    }
    while(pq.size()>=1)eliminate();
    cout<<"Winner(s):";
    for(int i=1;i<=n;i++)if(r[i].p!=0)cout<<" "<<i;
    cout<<"\n";
}
