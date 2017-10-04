#include<bits/stdc++.h>
using namespace std;
int n,k,a[100009];
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
void solve1()
{
    if(k==n){cout<<-1<<endl;return;}
    //for(int i=1;i<=n;i++)a[i]=i;
    for(int i=n;i>=n-k+1;i--)a[i]=i;
    a[1]=n-k;
    for(int i=2;i<=n-k;i++)a[i]=i-1;
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    cin>>n>>k;
    solve1();
    return 0;
}
