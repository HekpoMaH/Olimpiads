#include<bits/stdc++.h>
using namespace std;
int it[400009],idx[200009],a[200009],n;
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
    //it[pos]=max(it[pos*2],it[pos*2+1]);
}
void updin(int pos,int lef,int righ,int ql,int qr,int num)
{
    //cout<<pos<<" "<<ql<<" "<<lef<<" "<<righ<<" "<<righ<<endl;
    if(ql>righ||qr<lef)return;
    if(ql<=lef&&righ<=qr){it[pos]=num;cout<<pos<<" "<<num<<endl;return;}
    updin(pos*2,lef,(lef+righ)/2,ql,qr,num);
    updin(pos*2+1,(lef+righ)/2+1,righ,ql,qr,num);
}
int qry(int pos)
{
    int ans=0;
    pos=idx[pos];
    while(pos!=0)
    {
        ans=max(ans,it[pos]);
        pos/=2;
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    rec(1,1,n);
    int nq;
    cin>>nq;
    int t,x1,x2,x3;
    while(nq--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>x1;cout<<qry(x1)<<endl;
        }
        else
        {
            cin>>x1>>x2>>x3;
            updin(1,1,n,x1,x2,x3);
        }
    }
}
