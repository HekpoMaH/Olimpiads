#include<bits/stdc++.h>
using namespace std;
int n,a[100090],b[100090],p1,p2,br,nf;
int nod(int x,int y)
{
    int r;
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //br+=a[i]-a[i-1]-1;
    }
    sort(a+1,a+n+1);
    nf=nod(a[1],a[2]);
    for(int i=2;i<=n;i++)
    {
        nf=nod(nf,a[i+1]);

    }
    for(int i=1;i<=n;i++)
    {
        a[i]/=nf;
        br+=a[i]-a[i-1]-1;
    }
    //for(int i=1;i<=n;i++)cout<<b[a[i]]<<" ";cout<<endl;
    //cout<<p1<<endl;
    if(br%2!=0)cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}


