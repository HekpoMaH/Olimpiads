#include<iostream>
using namespace std;
int x,y;
unsigned long long n;
int f(unsigned long long mid)
{
if(y>=(x*n+mid)/(n+mid))
{
                      if(y<(x*n+mid-1)/(n+mid-1))return 0;
                      return -1;
}
return 1;
}
unsigned long long search()
{
unsigned long long l=1,r=2000000000;
while(l<=r)
{
long long mid=(r+l)/2;
int s=f(mid);
if(!s)return mid;
if(s==-1)r=mid-1;
if(s==1)l=mid+1;
}
}
int main()
{
cin>>x>>y>>n;
if(x==y)cout<<0<<endl;
else
{
unsigned long long b=search();
cout<<b<<endl;
}
}
