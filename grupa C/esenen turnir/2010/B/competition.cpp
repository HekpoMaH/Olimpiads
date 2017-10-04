#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int s[10000],p[10000],k,n;
struct he
{
    int lap;
    int runner;
    int crossingtime;
};
struct mass
{
    he hh[10000000];
};
int nh;
mass heap;
he add;
void heapify(int i, mass &k)
{
    int l=2*i,r=2*i+1;
    int largest;
    if(l<=nh&&k.hh[l].crossingtime<k.hh[i].crossingtime)largest=l;
    else largest=i;
    if(r<=nh and k.hh[r].crossingtime<k.hh[largest].crossingtime)largest=r;
    if(largest!=i)
    {
        swap(k.hh[i],k.hh[largest]);
        heapify(largest,k);
    }
}
void heapinsert(mass &hhh,he add)
{
    nh++;
    int i=nh;
    while(i>1 and hhh.hh[i/2].crossingtime>add.crossingtime)
    {
        hhh.hh[i]=hhh.hh[i/2];
        i/=2;
    }
    hhh.hh[i]=add;
}
void heapexmax(mass &hhh)
{
    hhh.hh[1]=hhh.hh[nh];
    nh--;
    heapify(1,hhh);
}
int main()
{
    scanf("%d%d",&k,&n);
    for(int i=0;i<k;i++)
    {
        scanf("%d%d",&s[i],&p[i]);
        add.lap=1;
        add.runner=i+1;
        add.crossingtime=s[i];
        heapinsert(heap,add);
    }
    //heapexmax(heap);
    //for(int i=1;i<=nh;i++)cout<<heap.hh[i].crossingtime<<endl;
    int i,j,crost;
    int last=0,brc=0,maxbr=0;
    while(nh>0&&maxbr<k)
    {
        //cout<<last<<endl;
        if(last!=heap.hh[1].crossingtime)
        {
            brc=1;
            last=heap.hh[1].crossingtime;
        }
        else brc++;
        if(brc>maxbr)maxbr=brc;
        i=heap.hh[1].runner;j=heap.hh[1].lap;crost=heap.hh[1].crossingtime;
        heapexmax(heap);
        if(j<n)
        {
            add.lap=j+1;
            add.runner=i;
            //cout<<i<<" "<<j<<" "<<crost<<endl;
            if((j+1)%p[i-1]>0)add.crossingtime=crost+s[i-1]+(j+1)%p[i-1]-1;
            else add.crossingtime=crost+s[i-1]+p[i-1]-1;
            //cout<<add.runner<<" "<<add.lap<<" "<<add.crossingtime<<endl;
            heapinsert(heap,add);
        }
    }
    printf("%d\n",maxbr);
    return 0;
}