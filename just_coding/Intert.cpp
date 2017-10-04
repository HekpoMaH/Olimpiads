#include<iostream>
using namespace std;
int it[200];
int a[100],idx[200];
int n,m,x,y,z,id;
void rec(int pos,int lef,int righ)
{

    if(lef==righ)
    {
        idx[lef]=pos;
        it[pos]=a[lef];
        return;
    }
    rec(pos*2,lef,(lef+righ)/2);
    rec(pos*2+1,(lef+righ)/2+1,righ);
    it[pos]=it[pos*2]+it[pos*2+1];
}
int sum(int pos,int lef,int righ,int ql,int qr)
{
    int s=0;
    if(ql<=lef&&righ<=qr)return it[pos];
    if(!(ql>(lef+righ)/2||lef>qr))s+=sum(pos*2,lef,(lef+righ)/2,ql,qr);
    if(!(ql>righ||qr<(lef+righ)/2+1))s+=sum(pos*2+1,(lef+righ)/2+1,righ,ql,qr);
    return s;
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
            //cout<<"A"<<endl;
            id=idx[y];
            while(id!=0)
            {
                it[id]+=z;
                id/=2;
            }
        }
        else cout<<sum(1,1,n,y,z)<<endl;
    }
}