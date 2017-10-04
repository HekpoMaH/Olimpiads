#include<iostream>
using namespace std;
struct he
{
    int st;
    int ind;
};
he heap[100];
int inheap[100],a[100];
int n,k,nh;
he x;
void insert(he element)
{
    nh++;
    heap[nh]=element;
    inheap[element.ind]=nh;
    int j=nh;
    while(j/2>0&&heap[j].st<heap[j/2].st)
    {
        inheap[heap[j].ind]=j/2;
        inheap[heap[j/2].ind]=j;
        swap(heap[j],heap[j/2]);
        j/=2;
    }
}
void deleteheap(int index)
{
    
    inheap[heap[nh].ind]=index;
    inheap[heap[index].ind]=nh;
    heap[index]=heap[nh];
    nh--;
    int j=index,mni;
    while(j*2<=nh)
    {
        if(j*2==nh)mni=j*2;
        else if(heap[j*2].st<heap[j*2+1].st)mni=j*2;
        else mni=j*2+1;
        if(heap[j].st>heap[mni].st)
        {
            inheap[heap[mni].ind]=j;
            inheap[heap[j].ind]=mni;
            swap(heap[j],heap[mni]);
            j=mni;
        }
        else break;
    }
    j=index;
    while(j/2>0&&heap[j].st<heap[j/2].st)
    {
        inheap[heap[j].ind]=heap[j/2].ind;
        inheap[heap[j/2].ind]=heap[j].ind;
        swap(heap[j],heap[j/2]);
        j/=2;
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=k;i++)
    {
        x.st=a[i];x.ind=i;
        insert(x);
    }for(int j=1;j<=k;j++)cout<<heap[j].st<<endl;
        cout<<"------"<<endl;
    for(int i=k+1;i<=n;i++)
    {
        deleteheap(inheap[i-k]);
        cout<<"inheap["<<i-k<<"]="<<inheap[i-k]<<endl;
        x.st=a[i];x.ind=i;
        insert(x);
        for(int j=1;j<=k;j++)cout<<heap[j].st<<endl;
        cout<<"------"<<endl;
    }
    return 0;
}