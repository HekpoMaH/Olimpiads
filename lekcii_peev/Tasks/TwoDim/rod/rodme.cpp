#include<iostream>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;
int a[1009],ps[1009],mem[1009][1009],zp;
int n;
int rec(int s,int e)
{
    if(s==e)return 0;
    int sum,mn=999999999,sm=ps[e]-ps[s-1],k,k1;

    for(int i=s;i<e;i++)
    {
        if(!(mem[s][i]) && s!=i){k=rec(s,i);mem[s][i]=k;}
        else k=mem[s][i];
        if(!(mem[i+1][e]) && i+1!=e){k1=rec(i+1,e);mem[i+1][e]=k1;}
        else k1=mem[i+1][e];

        sum=k+k1;
        if(sum<mn)mn=sum;
    }

    return mn+sm;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    clock_t tim=clock();
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],ps[i]=ps[i-1]+a[i];
    //memset(mem,31,sizeof(mem));
    zp=mem[5][5];

    cout<<rec(1,n)<<"\n";
    //cout<<clock()<<endl;
    //cout<<(double)((clock()-tim)/(CLOCKS_PER_SEC))<<"\n";
}
