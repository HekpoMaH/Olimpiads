#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct to4
{
    int t,st,t1,t2;
    int har,sti;
};
vector<to4> t;
int n,aa,bb,bt,nomta,a[20010],nomtb,nomtpredia=-1;
int ina,inb;
int t1,t2,st;
bool cmp(to4 a1,to4 a2)
{
    if(a1.t<a2.t)return true;
    if(a1.t==a2.t)
    {
        return (a1.har<a2.har);
    }
    return false;
}
int dw(int kk)
{
    int *p,rr;
    p=lower_bound(a,a+bt+1,kk);
    rr=p-a;
    if(rr==0)
    {
        if(a[0]==kk)
        {
            return 0;
        }
        else return -1;

    }
    else if(rr>bt)
    {
       if(a[bt]==kk)
       {
           return bt;
       }
       else return -1;
    }
    return rr;
}
int prednat(int nomt)
{
    int rez;
    rez=-1;
    for(int i=nomt-1;i>=0;i--)
    if(t[i].t<t[nomt].t||t[i].har==3)
    {
       rez=i;
       break;
    }
    return rez;

}
void smenistint1(int n2)
{
    int nompr;
    for(int i=nomta+1;i<=bt;i++)
    {
        if(t[i].t>t[n2].t)break;
        else
        {
            t[i].st=min(t[i].st,t[n2].sti);
            nompr=prednat(i);
            if(nompr>=0)t[i].st=min(t[i].st,t[nompr].st+t[i].t-t[nompr].t);
        }
    }
}
int nomtkraiint(int nomtnac)
{
    int nomint,rez,t1,t2;
    t1=t[nomtnac].t1;
    t2=t[nomtnac].t2;
    nomint=dw(t2);rez=-1;
    for(int i=nomint;i<=bt;i++)
    {
        if(t[i].t1==t1&&t[i].t2==t2&&t[i].har==2)
        {
            rez=i;break;
        }

    }
    return rez;
}
void smenistint(int n1,int n2)
{
    int nompr;
    nompr=prednat(n1);
    if(nompr>=0)t[n1].st=min(t[n1].st,t[nompr].st+t[n1].t-t[nompr].t);
    for(int i=n1+1;i<=bt;i++)
    {
        if(t[i].t>t[n2].t) break;
        else
        {
            t[i].st=min(t[i].st,t[n1].st+t[n2].sti);
            nompr=prednat(i);
            if (nompr>=0)
            {
                t[i].st=min(t[i].st,t[nompr].st+t[i].t-t[nompr].t);
            }
        }
    }
}
int main()
{
    int nomtkrai;
    cin>>n>>aa>>bb;
    t.resize(2*n+111);
    t[0].t=aa;
    t[0].st=0;
    t[0].har=3;
    t[0].t1=t[0].t2=aa;
    t[0].sti=0;
    t[1].t=bb;
    t[1].st=1000000;
    t[1].har=4;
    t[1].t1=t[1].t2=bb;
    t[1].sti=0;
    a[0]=aa;a[1]=bb;
    bt=1;
    for(int i=1;i<=n;i++)
    {
        cin>>t1>>t2>>st;
        bt++;
        t[bt].t=t1;
        t[bt].st=1000000;
        t[bt].har=1;
        t[bt].t1=t1;t[bt].t2=t2;
        t[bt].sti=st;
        a[bt]=t[bt].t;
        bt++;
        t[bt].t=t2;
        t[bt].st=1000000;
        t[bt].har=2;
        t[bt].t1=t1;t[bt].t2=t2;
        t[bt].sti=st;
        a[bt]=t[bt].t;
    }
    sort(t.begin(),t.begin()+bt+1,cmp);
    sort(a,a+bt+1);
    t[0].st=0;
    for(int i=0;i<=bt;i++)
    {
        if(t[i].har==3)nomta=i;
        else if(t[i].t1<=aa&&aa<=t[i].t2&&t[i].har==1){if(nomtpredia==-1)nomtpredia=i;}
        else if(t[i].har==4)
        {
            nomtb=i;
            break;
        }
    }

    //for(int i=0;i<=bt;i++)
    //{
        if(nomtpredia>=0)
        {
            for(int i=nomtpredia;i<=nomtb;i++)
            {
                if(t[i].t1>aa)break;
                else if(t[i].har==1)
                {
                    nomtkrai=nomtkraiint(i);
                    smenistint1(nomtkrai);
                }
            }
        }
        int nompr1;
    for(int i=nomta+1;i<=nomtb;i++)
    {
        int j=prednat(i);
        t[i].st=min(t[i].st,t[j].st+t[i].t-t[j].t);
        if(t[i].har==1)
        {
            nomtkrai=nomtkraiint(i);
            smenistint(i,nomtkrai);
        }
        else if(t[i].har==4)
        {
            nompr1=prednat(i);
            if(nompr1>=0)
            {
                t[i].st=min(t[i].st,t[nompr1].st+t[i].t-t[nompr1].t);
            }

        }
    }
    cout<<t[nomtb].st<<endl;
}
