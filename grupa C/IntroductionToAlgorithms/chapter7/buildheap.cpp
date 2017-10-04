#include<iostream>
using namespace std;
int n,nh,rp;
struct mas
{
    int a[100];
};
mas g;
void heapify(int i, mas &k)
{
    int l=2*i,r=2*i+1;
    int largest;
    if(l<=nh&&k.a[l]<k.a[i])largest=l;
    else largest=i;
    if(r<=nh and k.a[r]<k.a[largest])largest=r;
    if(largest!=i)
    {
        swap(k.a[i],k.a[largest]);
        heapify(largest,k);
    }
}
void buildheap(mas &c)
{
    nh=n;
    for(int i=n/2;i>=1;i--)heapify(i,c);
}
void heapexmax(mas &hhh,int index)
{
    hhh.a[index]=hhh.a[nh];
    nh--;
    heapify(index,hhh);
}
void findel(int el,long long i)
{
    if(i>nh)return;
    if(rp!=-1)return;//cout<<"i="<<i<<endl;
    //cout<<el.st<<" "<<el.pos<<" "<<heap[i].st<<" "<<heap[i].pos<<" left->"<<heap[2*i+1].st<<" "<<heap[2*i+1].pos<<" "<<" right->"<<heap[2*i+2].st<<" "<<heap[2*i+2].pos<<" "<<i<<endl;
    if(el==g.a[i]){rp=i;return;}
    if(el>=g.a[2*i])findel(el,2*i);
    if(el>=g.a[2*i+1])findel(el,2*i+1);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>g.a[i];
    buildheap(g);
    rp=-1;
    findel(3,1);
    //cout<<rp<<endl;
    heapexmax(g,rp);
    for(int i=1;i<=nh;i++)cout<<g.a[i]<<" ";
    cout<<endl;
    return 0;
}