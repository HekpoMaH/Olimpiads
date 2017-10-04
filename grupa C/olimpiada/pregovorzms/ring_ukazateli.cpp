#include<iostream>
#include<cstdio>
using namespace std;
struct sp
{
    int inf;
    sp *next;
};
int n,k;
sp *pend,*pbeg;
int main()
{
    scanf("%d%d",&n,&k);
    sp *q=0;
    for(int i=1;i<=n;i++)
    {
        q=new sp;//1
        q->inf=i;//2
        if(pend==0){q->next=q;pbeg=q;}//3a,3v
        else{pend->next=q;q->next=pbeg;}//3b,3g
        pend=q;
    }
    int br;
    sp *p=0,*ztr=0;
    int ans;
    for(int i=1;i<=n;i++)
    {
        br=1;
        while(br<=k)
        {
            p=q;
            q=q->next;
            //cout<<"qx="<<q->inf<<endl;
            //cout<<"br="<<br<<endl;
            br++;
        }
        cout<<"q="<<q->inf<<endl;
        if(i==n)ans=q->inf;
        p->next=q->next;
        if(q==pend)pend=p;
        if(q==pbeg)pbeg=q->next;
        if(pbeg==pend)pbeg=pend=0;
        ztr=q;
        q=q->next;
        delete ztr;
        scanf("%d",&k);
    }
    cout<<ans<<endl;
    return 0;
}