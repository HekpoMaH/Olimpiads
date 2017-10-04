#include<iostream>
#include<string.h>
using namespace std;
int main()
{
string n1,m1;
int k,r;
cin>>n1>>m1>>k;
int n[106],m[106],l[107];
int i,j;
int dn=n1.size();
int dm=m1.size();
if(dn<dm)
{
string x=n1;
n1=m1;
m1=x;
int xx=dn;
dn=dm;
dm=xx;
}
for(i=0;i<dn;i++)n[i]=(int)n1[i]-48;
for(i=0;i<dm;i++)m[i]=(int)m1[i]-48;
int d=dn-dm;
int ost=0;
for(i=dn-1;i>0;i--)
{
if(i-d>=0)r=m[i-d];
else r=0;
l[i]=(ost+n[i]+r)%10;
ost=(ost+n[i]+r)/10;
}
if(d==0)r=m[0]; else r=0;
l[0]=r+n[0]+ost;
int f[108];
ost=0;
for(i=dn-1;i>0;i--)
{
f[i]=(l[i]*k+ost)%10;
ost=(l[i]*k+ost)/10;
}
f[0]=l[i]*k+ost;
bool p=0;
for(i=0;i<dn;i++)
{
                 if(f[i])
                 {
                         cout<<f[i];
                         p=1;
                 }
                 else
                 {
                 if(p)cout<<f[i];
                 }
}
cout<<endl;
}
