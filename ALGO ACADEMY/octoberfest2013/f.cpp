#include<bits/stdc++.h>
using namespace std;
struct el
{
    int val,pos;
};
el a[50009];
int eln;
int n,c;
int solve(int number)
{
    int l=0,r=eln,md,ans=0;
    while(l<=r)
    {
        md=(l+r)/2;//cout<<number<<" "<<md<<" "<<a[md].val<<" "<<a[md+1].val<<endl;
        if(number>=a[md].val&&number<=a[md+1].val)
        {
            ans=md;
            r=md-1;
        }
        if(number<a[md].val)r=md-1;
        if(number>a[md].val)l=md+1;
    }
    //if(number==5)cout<<ans<<endl;
    return a[ans].pos;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>c;
    int x;
    a[0].val=-10;a[0].pos=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x!=0)
        {
            eln++;
            a[eln].pos=i;
            a[eln].val=x;
        }
    }
    a[eln+1].val=99999999;
    //cout<<"-------------"<<endl;
    //for(int i=1;i<=eln;i++)cout<<a[i].pos<<" ";
    //cout<<endl;
    //cout<<"--------"<<endl;
    for(int i=1;i<c;i++)
    {
        cin>>x;
        cout<<solve(x)<<" ";
    }
    cin>>x;
    cout<<solve(x)<<endl;
}
