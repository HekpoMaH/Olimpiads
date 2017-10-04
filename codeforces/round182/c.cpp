#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
using namespace std;
long long n,a[2009];
long long sum,br,sum2,ms,br1,br0,lp,sad,ltf;
bool cmp(long long a,long long b)
{
    if(a<b)return true;
    return false;
}
int main()
{
    cin>>n;
    for(int i=1;i<=2*n-1;i++)cin>>a[i];
    sort(a+1,a+2*n-1+1,cmp);
    lp=2*n;
    a[0]=-9999;
    //cout<<"WW"<<endl;
    for(int i=1;i<=2*n-1;i++)
    {
        sum+=abs(a[i]);
        if(a[i]<0)br1++;
    }
    if(n==2&&(br1==3||br1==1))
    {
        long long mn=99999;
        for(int i=1;i<=2*n-1;i++)
        {
            mn=min(mn,(long long)(abs(a[i])));
        }//cout<<mn<<endl;
        sum-=2*mn;
    }
    cout<<sum<<endl;
}
//-++++
/*
-----
+++--
+-+++
++--+
+--+-
+++++-
+++-+++
+-----+
-++---+
*/
