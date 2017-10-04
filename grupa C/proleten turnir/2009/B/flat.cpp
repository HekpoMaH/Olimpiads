#include<iostream>
#include<cstdio>
using namespace std;
struct element
{
    long long st,pos;
};
struct mass
{
    element f[1000000];
};
element a[1000000];
mass heap;
long long n,k,s,mn=9999999999LL,minpos,nh,rp;
void findel(element el,long long i)
{
    //cout<<"i="<<i<<endl;
    if(i>k)return;
    if(rp!=-1)return;
    //cout<<el.st<<" "<<el.pos<<" "<<heap.f[i].st<<" "<<heap.f[i].pos<<" left->"<<heap.f[2*i].st<<" "<<heap.f[2*i].pos<<" "<<" right->"<<heap.f[2*i+1].st<<" "<<heap.f[2*i+1].pos<<" "<<i<<endl;
    if(el.st==heap.f[i].st&&el.pos==heap.f[i].pos){rp=i;return;}
    if((el.st>=heap.f[2*i].st||(el.st==heap.f[2*i].st&&el.pos>=heap.f[2*i].pos))&&2*i<=k)findel(el,2*i);
    if((el.st>=heap.f[2*i+1].st||(el.st==heap.f[2*i+1].st&&el.pos>=heap.f[2*i+1].pos))&&2*i+1<=k)findel(el,2*i+1);
}
void heapify(int i, mass &rrr)
{
    int l=2*i,r=2*i+1;
    int largest;
    if((l<=nh&&rrr.f[l].st<rrr.f[i].st)||(l<=nh&&rrr.f[l].st==rrr.f[i].st&&rrr.f[l].pos<rrr.f[i].pos))largest=l;
    else largest=i;
    if((r<=nh&&rrr.f[r].st<rrr.f[i].st)||(r<=nh&&rrr.f[r].st==rrr.f[i].st&&rrr.f[r].pos<rrr.f[i].pos))largest=r;
    if(largest!=i)
    {
        swap(rrr.f[i],rrr.f[largest]);
        heapify(largest,rrr);
    }
}
void heapinsert(mass &hhh,element add)
{
    nh++;
    int i=nh;
    while(i>1&&((hhh.f[i/2].st>add.st)||(hhh.f[i/2].st==add.st&&hhh.f[i/2].pos>add.pos)))
    {
        hhh.f[i]=hhh.f[i/2];
        i/=2;
    }
    hhh.f[i]=add;
}
void heapexmax(mass &hhh,int index)
{
    hhh.f[index]=hhh.f[nh];
    nh--;
    heapify(index,hhh);
}
element addd;
int main()
{
    //ios::sync_with_stdio(false);
    scanf("%I64d%I64d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i].st);
        a[i].pos=i;
    }
    for(int i=1;i<=k;i++)
    {
        s+=a[i].st;
        addd.st=a[i].st;
        addd.pos=a[i].pos;
        heapinsert(heap,addd);
    }
    
    for(int i=k+1;i<=n;i++)
    {
        if(s-k*heap.f[1].st<mn)
        {
            mn=s-k*heap.f[1].st;
            minpos=i-k;
        }
        //for(int v=1;v<=k;v++)cout<<heap.f[v].st<<" ";
        //cout<<endl;
        s+=a[i].st;
        s-=a[i-k].st;
        rp=-1;
        for(int dr=1;dr<=nh;dr++)if(a[i-k].st==heap.f[dr].st&&a[i-k].pos==heap.f[dr].pos)rp=dr;
        swap(heap.f[i],heap.f[rp]);
        heapify(1,heap);
        for(int tr=1;tr<=nh;tr++)
    {
        if(tr*2<=nh&&(heap.f[tr*2].st<heap.f[tr].st||(heap.f[tr*2].st==heap.f[tr].st&&heap.f[tr*2].pos<heap.f[tr].pos))){cout<<"NOHEAP"<<endl;return 0;}
        if(tr*2+1<=nh&&(heap.f[tr*2+1].st<heap.f[tr].st||(heap.f[tr*2+1].st==heap.f[tr].st&&heap.f[tr*2+1].pos<heap.f[tr].pos))){cout<<"NOHEAP"<<endl;return 0;}
    }
        if(rp==-1){cout<<a[i-k].st<<" ";cout<<"BOOM"<<endl;return 0;}
        addd.st=a[i].st;
        addd.pos=a[i].pos;
        heapinsert(heap,addd);
    }
    printf("%I64d\n%I64d\n",mn,minpos);
    return 0;
}