#include<iostream>
using namespace std;
int n,m,d[1<<13][1<<13],a[13][1<<13];
void go(int p,int profile,int len)
{
    if(len==n)
    {
        //cout<<p<<" "<<profile<<endl;
        d[p][profile]=1;
        return;
    }
    if(!(p&(1<<len)))
    {
        go(p,profile+(1<<len),len+1);
        if(len<n-1)if(!(p&(1<<(len+1))))go(p,profile,len+2);
    }
    else go(p,profile,len+1);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<1<<n;i++)go(i,0,0);
    a[1][0]=1;
    for(int i=1;i<=m+1;i++)
    {
        for(int p1=0;p1<1<<n;p1++)
        {
            for(int p2=0;p2<1<<n;p2++)
            {
                a[i][p1]+=a[i-1][p2]*d[p2][p1];
            }
        }
    }
    /*for(int i=1;i<=m+1;i++)
    {
        for(int p1=0;p1<1<<n;p1++)
        {
            cout<<a[i][p1]<<" ";
        }
        cout<<endl;
    }*/
    cout<<a[m+1][0]<<endl;
    return 0;
}