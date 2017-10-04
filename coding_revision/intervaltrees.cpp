#include<iostream>
using namespace std;
int it[200],a[100],idx[100];
int n,m,x,y,z,id;
void rec(int pos,int l,int r)
{
    if(l==r)
    {
        idx[l]=pos;
        it[pos]=a[l];
        return;
    }
    rec(pos*2,l,(l+r)/2);
    rec(pos*2+1,(l+r)/2+1,r);
    it[pos]=it[pos*2]+it[pos*2+1];
}
int sum(int pos,int l,int r,int ql,int qr)
{
    int s=0;
    if(ql<=l&&r<=qr)return it[pos];
    if(!(ql>(l+r)/2||l>qr))s+=sum(pos*2,l,(l+r)/2,ql,qr);
    if(!(ql>r||qr<(l+r)/2+1))s+=sum(pos*2+1,(l+r)/2+1,r,ql,qr);
    return s;
}
void updint(int pos,int l,int r,int ql,int qr,int un)
{
    //cout<<l<<" "<<r<<" "<<pos<<endl;
    //this is not correct
    if(ql<=l&&r<=qr)
    {
        it[pos]+=un*(r-l+1);
        //cout<<pos<<" "<<l<<" "<<r<<endl;
        if(l==r)return;
    }
    if(l==r)return;
    if(!(ql>(l+r)/2||l>qr))updint(pos*2,l,(l+r)/2,ql,qr,un);
    if(!(ql>r||qr<(l+r)/2+1))updint(pos*2+1,(l+r)/2+1,r,ql,qr,un);
    it[pos]=it[pos*2]+it[pos*2+1];
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    rec(1,1,n);
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        if(x==1)
        {
            id=idx[y];
            while(id!=0)
            {
                it[id]+=z;
                id/=2;
            }
        }
        else if(x==3)
        {
            int d;
            cin>>d;
            updint(1,1,n,y,z,d);
        }
        else cout<<sum(1,1,n,y,z)<<endl;
    }
}
