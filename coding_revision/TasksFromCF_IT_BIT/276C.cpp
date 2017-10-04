//little girl and maximum sum CF rnd 169
//solved by BIT
#include<iostream>
#include<algorithm>
using namespace std;
long long bit[400009];
long long n,q;
long long a[200009],b[200009];
void upd(long long pos,long long val)
{
    while(pos<=n)
    {
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}
long long give(long long pos)
{
    long long davam=0;
    while(pos!=0)
    {
        davam+=bit[pos];
        pos-=(pos&-pos);
    }
    return davam;
}
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        upd(x,1);upd(y+1,-1);
    }
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        b[i]=give(i);
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
        sum+=a[i]*b[i];
    }cout<<endl;
    cout<<sum<<endl;
}
