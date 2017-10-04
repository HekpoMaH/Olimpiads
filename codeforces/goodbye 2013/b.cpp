#include<bits/stdc++.h>
using namespace std;
int n,a[309],s,cntr;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
    int dir=1,i=1;
    while(s>0)
    {
        if(a[i]!=0)cout<<"P",a[i]--,s--,cntr++;
        if(dir==1)cout<<"R",cntr++;
        else cout<<"L",cntr++;
        i+=dir;
        if(i==n&&dir==1)dir=-dir;
        if(i==1&&dir==-1)dir=-dir;

    }
    cout<<cntr<<endl;
    cout<<"\n";
}
