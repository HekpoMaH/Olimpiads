#include<iostream>
using namespace std;
int n,x,y,s,mx,my,mnx,mny,br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>s;
        mx=max(x,mx);
        my=max(y,my);
        mnx=min(x,mnx);
        mny=min(y,mny);
    }
    mx-=mnx;
    my-=mny;
    mx/=s;
    my/=s;
    mx++;my++;
    for(int i=1;i<=min(mx,my);i++)
    {
        //cout<<mx-i+1<<" "<<my-i+1<<endl;
        br+=(mx-i+1)*(my-i+1);
    }
    cout<<br<<endl;
    return 0;
}