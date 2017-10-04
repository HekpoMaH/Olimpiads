#include<iostream>
#include<algorithm>
using namespace std;
int a[22],tab[22][22];
int s;
int n,mn=2000000;
int test(int i)
{
    int lef=0,righ=0,br=0;
    //cout<<"i="<<i<<endl;
    while(br<=n)
    {
        br++;
        if(i%2==0)lef+=a[br];
        else righ+=a[br];//cout<<i%2<<endl;
        i/=2;
    }
    //cout<<"abs="<<abs(lef-righ)<<endl;
    return abs(lef-righ);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    s=1;
    for(int i=1;i<=n;i++)
    {
        s*=2;
    }
    //cout<<s<<endl;
    for(int i=1;i<=s;i++)
    {
        mn=min(mn,test(i));
    }
    cout<<mn<<endl;
    return 0;
}