#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
int a[1000006],b[1000005],a1[10000006],b1[10000005];
int nod(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void dit(int x)
{
    int del=2;
    while(x!=1)
    {
        if(x%del==0)
        {
            a1[del]++;
            x/=del;
            //cout<<"del="<<del<<endl;
        }
        else del++;
    }
}
void dit2(int x)
{
    int del=2;
    while(x!=1)
    {
        if(x%del==0)
        {
            b1[del]++;
            x/=del;
            //cout<<"del="<<del<<endl;
        }
        else del++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int pr1=1,pr2=1,mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];mx=max(mx,a[i]);
        dit(a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];mx=max(mx,b[i]);
        dit2(b[i]);
    }
    for(int i=1;i<=mx;i++)
    {
        if(a1[i]<b1[i])b1[i]-=a1[i],a1[i]=0;
        else a1[i]-=b1[i],b1[i]=0;
    }
    
    vector<int> ans1,ans2;
    ans1.clear();ans2.clear();
    for(int i=1;i<=mx;i++)
    { 
        //cout<<i<<endl;
        if(b1[i]>0)
        {
            //cout<<"b"<<" "<<b1[i]<<endl;
            while(b1[i]--)ans2.push_back(i);
        }
        if(a1[i]>0)
        {
            //cout<<"a"<<" "<<a1[i]<<endl;
            while(a1[i]--)ans1.push_back(i);
        }
    }
    ans1.push_back(1);
    ans2.push_back(1);
    cout<<ans1.size()<<" "<<ans2.size()<<endl;
    for(int i=0;i<ans1.size()-1;i++)
    {
        cout<<ans1[i]<<" ";
    }cout<<ans1[ans1.size()-1]<<endl;
    for(int i=0;i<ans2.size()-1;i++)
    {
        cout<<ans2[i]<<" ";
    }
    cout<<ans2[ans2.size()-1]<<endl;
    return 0;
}