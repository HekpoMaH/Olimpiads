#include<iostream>
using namespace std;
struct hh
{
    int el,rind;
};
int n;
hh heap[100];
int inheap[100],hsize;
int a[100];
void addtoheap(int elm,int ind)
{
    hsize++;
    heap[hsize].el=elm;heap[hsize].rind=ind;
    inheap[ind]=hsize;
    int i=hsize;
    while(i/2>0&&(heap[i].el<heap[i/2].el||(heap[i].el==heap[i/2].el&&heap[i].rind<heap[i/2].rind)))
    {
        inheap[heap[i].rind]=i/2;
        inheap[heap[i/2].rind]=i;
        swap(heap[i],heap[i/2]);
        i/=2;
    }
}
void removeel(int ind)
{
    int largest,i;
    inheap[heap[hsize].rind]=ind;
    inheap[heap[ind].rind]=hsize;
    swap(heap[ind],heap[hsize]);
    hsize--;
    i=ind;
    while(i*2<=hsize)
    {
        if(i*2==hsize)
        {
            largest=hsize;
        }
        else if(heap[i*2].el<heap[i*2+1].el)largest=i*2;
        else largest=i*2+1;
        if(heap[i].el>heap[largest].el)
        {
            inheap[heap[largest].rind]=i;
            inheap[heap[i].rind]=largest;
            swap(heap[i],heap[largest]);
            i=largest;
        }
        else break;
    }
    i=hsize;
    while(i/2>0&&(heap[i].el<heap[i/2].el))
    {
        inheap[heap[i].rind]=i/2;
        inheap[heap[i/2].rind]=i;
        swap(heap[i],heap[i/2]);
        i/=2;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        addtoheap(a[i],i);
    }
    for(int i=1;i<=hsize;i++)cout<<heap[i].el<<" "<<heap[i].rind<<endl;
    removeel(inheap[2]);
    for(int i=1;i<=hsize;i++)cout<<heap[i].el<<" "<<heap[i].rind<<endl;
    return 0;
}