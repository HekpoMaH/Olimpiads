#include<bits/stdc++.h>
using namespace std;
const int maxn=1000009;
long long n,k,len;
long long a[maxn],inheap[maxn],sum;
struct el
{
    long long val;
    long long idx;
};
el heap[maxn];
void addheap(long long value,long long realidx)
{
    long long i;
    len++;
    heap[len].val=value;
    heap[len].idx=realidx;
    inheap[realidx]=len;
    i=len;
    while(i/2>0&&heap[i].val<heap[i/2].val)
    {
        inheap[heap[i].idx]=i/2;
        inheap[heap[i/2].idx]=i;
        swap(heap[i],heap[i/2]);
        i/=2;
    }
}
void delheap(long long idx)
{
    long long mini,i=idx;
    inheap[heap[len].idx]=idx;
    inheap[heap[idx].idx]=len;
    swap(heap[idx],heap[len]);
    len--;
    while(i*2<=len)
    {
        if(i*2==len)mini=i*2;
        else if(heap[i*2].val<heap[i*2+1].val)mini=i*2;
        else mini=i*2+1;
        if(heap[i].val>heap[mini].val)
        {
            inheap[heap[mini].idx]=i;
            inheap[heap[i].idx]=mini;
            swap(heap[i],heap[mini]);
            i=mini;
        }
        else break;
    }
    i=idx;
    while(i/2>0&&heap[i].val<heap[i/2].val)
    {
        inheap[heap[i].idx]=i/2;
        inheap[heap[i/2].idx]=i;
        swap(heap[i],heap[i/2]);
        i/=2;
    }
}
long long minheap()
{
    return heap[1].val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=k;i++)
    {
        addheap(a[i],i);
        sum+=a[i];
    }
    long long mn=sum-k*minheap();
    int mnidx;
    for(int i=k+1;i<=n;i++)
    {
        sum+=a[i];
        sum-=a[i-k];
        delheap(inheap[i-k]);
        addheap(a[i],i);
        long long curr=sum-k*minheap();
        if(mn>curr)
        {
            mn=curr;
            mnidx=i-k+1;
        }
    }
    cout<<mn<<"\n"<<mnidx<<"\n";
}
