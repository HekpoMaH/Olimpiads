#include<iostream>
using namespace std;
int it[5*128],n,a[128];
void update(int pos,int x)
{
    while(pos<=5*128)
    {
        it[pos]+=x;
        pos+=pos&(-pos);
    }
}
int find(int i,int j)
{
    int sum1=0,sum2=0;
    while(j>=1)sum2+=it[j],j-=j&(-j);
    i--;
    while(i>=1)sum1+=it[i],i-=i&(-i);
    return (sum2-sum1);
}
void read()
{
    int i,t,x,y,k;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];update(i,a[i]);
    }
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>t>>x>>y;
        if(t==1)update(x,y-a[x]),a[x]=y;
        else cout<<find(x,y)<<endl;
    }
}
int main()
{
    read();
    return 0;
}
