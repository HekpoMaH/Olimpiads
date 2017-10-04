#include<bits/stdc++.h>
using namespace std;
int b[6];
int arr[5*(int)(1e5)+6],uarr,arr2[5*(int)(1e5)+6],u1,u2,ua2,sum;
void read()
{
    for(int i=1;i<=5;i++)cin>>b[i];
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=b[i];j++)arr[++uarr]=i,sum++ ;
    }
}
void solve()
{
    u1=1;u2=uarr;
    int uk1=1,uk2=sum;
    while(uk1<=uk2)
    {
        arr2[uk1]=arr[u2];u2--;uk1++;
        if(uk1<=uk2)arr2[uk1]=arr[u1],u1++,uk1++;
        arr2[uk2]=arr[u2];u2--;uk2--;
        if(uk1<=uk2)arr2[uk2]=arr[u1],u1++;uk2--;
    }
    int ans=0;
    for(int i=1;i<=sum;i++)
    {
        if(i<sum)ans+=max(abs(arr2[i]+arr2[i+1])-5,0);
        cerr<<arr2[i]<<" ";
    }cerr<<endl;
    cout<<ans<<endl;
}
int main()
{
    read();
    solve();
}
