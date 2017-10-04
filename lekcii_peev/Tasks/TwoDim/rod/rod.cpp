//rod
#include<iostream>
using namespace std;
long long a[1000],p[1000],n,mem[1000][1000];
int rec(int s,int e)
{
    if(s==e)return 0;
    int sum,mn=999999999,sm=p[e]-p[s-1],k,k1;
    
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i]=a[i]+p[i-1];
    }
    cout<<rec(1,n)<<"\n";
    return 0;
}