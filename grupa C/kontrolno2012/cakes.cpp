#include<iostream>
#include<algorithm>
using namespace std;
int n;
int cakes[50];
int brm=0,brmm=0,si,ll,mxs=0,mxims,mx=0,mxim;
int ffd()
{
    for(int i=1;i<=n;i++)
    {
        if(cakes[i]!=mx)return i;
    }
    return -1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>cakes[i];
    //sort(cakes+1,cakes+n+1);
    
    for(int i=n;i>=1;i--)
    {
        mx=max(mx,cakes[i]);//cout<<"aaa"<<endl;
        if(mx==cakes[i])mxim=i;
    }
    for(int i=n;i>=1;i--)
    {
        if(cakes[i]<mx)mxs=max(mxs,cakes[i]);
        if(mxs==cakes[i])mxims=i;
    }
    for(int i=n;i>=1;i--)
    {
        if(cakes[i]==mx)brm++;
    }
    for(int i=n;i>=1;i--)
    {
        if(cakes[i]==mxs)brmm++;
    }
    
    if(brm%2==0)
    {
        if(brmm==0){cout<<"CAKE "<<mxim-1<<" PEACES 1"<<endl;return 0;}
        //si=ffd();
        //cout<<"CAKE "<<si<<" PEACES 1"<<endl;
        return 0;
    }
    if(brm%2==1)
    {
        if(brmm%2==1)cout<<"CAKE "<<mxim-1<<" PEACES "<<cakes[mxim]-cakes[mxims]<<endl;
        if(brmm==0){cout<<"CAKE 0 PEACES 1"<<endl;return 0;}
        if(brmm%2==0)cout<<"CAKE "<<mxim-1<<" PEACES "<<cakes[mxim]-cakes[mxims]+1<<endl;
        return 0;
    }
    /*if(brmm%2==1)
    {
        cout<<"CAKE "<<mxim<<" PEACES "<<cakes[mxim]-cakes[mxims]<<endl;
        return 0;
    }
    if(brmm%2==0)
    {
        cout<<"CAKE "<<si<<" PEACES "<<ms-cakes[si]+1<<endl;
    }*/
    //cout<<brm<<" "<<brmm<<" "<<ms<<endl;
    return 0;
}