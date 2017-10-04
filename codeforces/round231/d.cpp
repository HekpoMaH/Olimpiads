#include<bits/stdc++.h>
using namespace std;
int a[1009];
int n,ans1=(1<<30),ans2,ans3;
void chek(int st)
{
    int me=0;
    for(int i=2;i<=n;i++)
    {
        if(abs(a[i]-(a[i-1]+(i-1)*st))>me)me=abs(a[i]-(a[i-1]+(i-1)*st));
    }
    if(ans1>me)
    {
        ans1=me;
        ans2=a[1];
        ans3=st;
    }
    me=abs(a[2]-st-a[1]);
    for(int i=3;i<=n;i++)
    {
        if(abs(a[i]-(a[i-1]+(i-2)*st))>me)me=abs(a[i]-(a[i-1]+(i-2)*st));
    }
    if(ans1>me)
    {
        ans1=me;
        ans2=a[2];
        ans3=st;
    }

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int stapka=1;stapka<=10000;stapka++)
    {
        chek(stapka);
    }
    cout<<ans1<<endl<<ans2<<" "<<ans3<<endl;
}
