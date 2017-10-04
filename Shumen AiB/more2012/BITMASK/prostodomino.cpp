#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[100],b[100],mindiv=943634,minmask;
void check(int bm)
{
    int s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
        if(bm&(1<<i))s1+=a[i+1],s2+=b[i+1];
        else s1+=b[i+1],s2+=a[i+1];
    }
    if(abs(s1-s2)<mindiv)mindiv=abs(s1-s2),minmask=bm;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int mask=0;mask<1<<n;mask++)
    {
        check(mask);
    }
    cout<<mindiv<<endl;
    string ans="";
    for(int i=0;i<n;i++)
    {
        if(minmask&(1<<i))cout<<1;
        else cout<<0;
    }
    
    return 0;
}
/*
3
1 3
2 1
1 2
*/