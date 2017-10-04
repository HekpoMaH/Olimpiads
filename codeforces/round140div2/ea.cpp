#include<iostream>
#include<cstring>
using namespace std;
long long mn[100004];
long long mx[100004];
long long n,m,x;
int main()
{
    memset(mn,63,sizeof(mn));
    //memset(mx,63,sizeof(mx));
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(mn[x]>i)mn[x]=i;
        if(mx[x]<i)mx[x]=i;
    }
    //for(int i=1;i<=n;i++)cout<<mn[i]<<" "<<mx[i]<<endl;
    long long vs=0,ps=0;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        vs+=mn[x];ps+=(n-mx[x]+1);
    }
    cout<<vs<<" "<<ps<<endl;
    return 0;
}