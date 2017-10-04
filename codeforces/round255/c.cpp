#include<iostream>
using namespace std;
int main()
{
    int a[100040],l[100040],r[100040],n,i,o=1;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    if(n==2)
    {
        cout<<2<<endl;
        return 0;
    }
    l[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>a[i-1])l[i]=l[i-1]+1;
        else l[i]=1;
    }
    r[n+1]=0;
    for(i=n;i>0;i--)
      if(a[i]<a[i+1])r[i]=r[i+1]+1;
      else r[i]=1;
    for(i=2;i<n;i++)
    {
        o=max(o,l[i]+1);
        o=max(o,r[i]+1);
        if(a[i-1]+1<a[i+1])o=max(o,l[i-1]+1+r[i+1]);
    }
    cout<<o<<endl;
}
