#include<iostream>
using namespace std;
int it[20000];
int idx[20000];
int a[10000];
int n,x,y,z,p;
void rec(int pos,int l,int r)
{
    if(l==r)
    {
        idx[l]=pos;
        //it[pos]=a[l];
        return;
    }
    rec(pos*2,l,(l+r)/2);
    rec(pos*2+1,(l+r)/2+1,r);
    //it[pos]=it[pos*2]+it[pos*2]+1;
}
int sum(int pos,int l,int r,int ql,int qr)
{
    int s=0;
    if(ql<=l&&r<=qr)return it[pos];
    if(!(ql>(l+r)/2||l>qr))s+=sum(pos*2,l,(l+r)/2,ql,qr);
    if(!(ql>r||qr<(l+r)/2+1))s+=sum(pos*2+1,(l+r)/2+1,r,ql,qr);
    return s;
}
int main()
{
    cin>>n;
    rec(1,1,n);
    while(1)
    {
        cin>>x;
        if(x==0)return 0;
        cin>>y>>z;
        if(x==1)
        {
            a[y]+=z;
            p=idx[y];
            while(p)
            {
                it[p]+=z;
                p/=2;
            }
        }
        else cout<<sum(1,1,n,y,z)<<endl;
    }
}