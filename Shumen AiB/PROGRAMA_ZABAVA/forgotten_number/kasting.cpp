#include<iostream>
#include<cstring>
using namespace std;
int n,a,b,c,mn,mx,mid,xx[10009],pr,idx,n1;
int wtf;
int main()
{
    cin>>wtf;
    cin>>n>>a>>b>>c;//n1=n;
    if(wtf==2)cout<<min(min(a,b),c)<<endl;
    else
    {
        mn=min(min(a,b),c);mx=max(max(a,b),c);
        if(a!=mn&&a!=mx)mid=a;int br=0;
        if(b!=mn&&b!=mx)mid=b;
        if(c!=mn&&c!=mx)mid=c;
        if(mid==0)mid=mn;
        for(int i=n;i>=n-mx+1;i--)xx[i]+=1;
        for(int i=mid;i>=n-mid+1;i--)xx[i]+=2;
        for(int i=1;i<=mn;i++)xx[i]+=3;
        for(int i=1;i<=n;i++)if(xx[i]==6)n1++;
        memset(xx,0,sizeof(xx));
        for(int i=n;i>=n-mx+1;i--)xx[i]+=1;
        for(int i=1;i<=mid;i++){xx[i]+=1;}
        for(int i=1;i<=n;i++){if(xx[i]==1)pr++;}
        if(pr-mn>=0)idx=0;
        else idx=mn-pr;
        //cout<<pr<<" "<<idx<<endl;
        cout<<min(idx,n1)<<endl;
    }

}
