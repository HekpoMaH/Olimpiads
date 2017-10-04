#include<iostream>
using namespace std;
int l[1000001],it[7000001],n,s[1000001];
int ud(int u)
{
    int x=1,le=1,r=n;
    while(le!=r)
    {
        it[x]++;
        if(it[x*2]+u>(le+r)/2)
        {
            u+=it[x*2];
            x=x*2+1;
            le=(le+r)/2+1;
        }
        else
        {
            x*=2;
            r=(le+r)/2;
        }
    }
    it[x]++;
    return le;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>l[i];
        if(i==0)s[i]=l[i];
        else s[i]=l[i]+s[i-1];
    }
    for(i=n-1;i>=0;i--)
        l[i]=ud(s[i]+1);
    for(i=0;i<n;i++)
        cout<<l[i]<<'\n';
}
