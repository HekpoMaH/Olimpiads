//i love you tONY
//actually i dont so much
#include<iostream>
#include<algorithm>
using namespace std;
long long a[400009];
long long it[4000009];
long long idx[400009];
long long c[4000009];
long long n,q;
void rec(long long pos,long long l,long long r)
{
    if(l==r)
    {
        idx[l]=pos;
        //it[pos]=a[l];
        return;
    }
    rec(pos*2,l,(l+r)/2);
    rec(pos*2+1,(l+r)/2+1,r);
    //it[pos]=it[pos*2]+it[pos*2+1];
}
void upd(long long pos,long long l,long long r,long long ql,long long qr,long long un)
{
    if(ql<=l&&r<=qr)
    {
        it[pos]+=(r-l+1)*un;
        c[pos]+=un;
        return;
    }
    if(c[pos]!=0&&l!=r)
    {
        it[pos*2]+=c[pos]*((l+r)/2-l+1);
        it[pos*2+1]+=c[pos]*(r-((l+r)/2+1)+1);
        c[pos*2]+=c[pos];
        c[pos*2+1]+=c[pos];c[pos]=0;

    }
    if(!(ql>(l+r)/2||l>qr))upd(pos*2,l,(l+r)/2,ql,qr,un);
    if(!(ql>r||qr<(l+r)/2+1))upd(pos*2+1,(l+r)/2+1,r,ql,qr,un);
}
long long sum(long long pos,long long l,long long r,long long ql,long long qr)
{
    if(c[pos]!=0&&l!=r)
    {
        //if(pos*2>800000||pos*2+1>800000)cout<<"KABOOM"<<" "<<pos<<" "<<l<<" "<<r<<endl;
        it[pos*2]+=c[pos]*((l+r)/2-l+1);
        it[pos*2+1]+=c[pos]*(r-((l+r)/2+1)+1);
        c[pos*2]+=c[pos];
        c[pos*2+1]+=c[pos];c[pos]=0;
    }
    long long s=0;
    if(ql<=l&&r<=qr)return it[pos];
    if(!(ql>(l+r)/2||l>qr))s+=sum(pos*2,l,(l+r)/2,ql,qr);
    if(!(ql>r||qr<(l+r)/2+1))s+=sum(pos*2+1,(l+r)/2+1,r,ql,qr);
    return s;
}
long long b[1000009],used[1000009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    //rec(1,1,n);
    for(int i=1;i<=q;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        used[x+1]+=z;used[y+2]-=z;
        //upd(1,1,n,x+1,y+1,z);

    }
    //cout<<idx[4]<<endl;
    //for(int i=1;i<=n;i++)b[i]=sum(1,1,n,i,i);//,cout<<"query= "<<i<<endl;;
    //sort(a+1,a+n+1);sort(b+1,b+n+1);//if(n==200000)for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    long long summ=0;
    for(int i=1;i<=n;i++)summ+=used[i],cout<<summ<<" ";
    cout<<endl;
    //cout<<summ<<endl;
}

