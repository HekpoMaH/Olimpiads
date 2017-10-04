#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
string a1,c1;
int a[106],b,c[106],d,i,j;
cin>>a1>>b>>c1>>d;
int da=a1.size();
int dc=c1.size();
for(i=0;i<da;i++)a[i]=(int)a1[i]-48;
for(i=0;i<dc;i++)c[i]=(int)c1[i]-48;
int x[107],y[107],z[108];
if(a1=="0" || b==0)
{
x[0]=1;
x[1]=0;
}
else
{
int ost=0;
for(i=da-1;i>0;i--)
{
x[i+1]=(a[i]*b+ost)%10;
ost=(a[i]*b+ost)/10;
}
x[1]=a[0]*b+ost;
x[0]=da;
}
if(c1=="0" || d==0)
{
y[0]=1;
y[1]=0;
}
else
{
if(d==10)
{
y[0]=dc+1;
for(i=0;i<dc;i++)y[i+1]=c[i];
y[dc+1]=0;
}
else
{
int ost=0;
for(i=dc-1;i>0;i--)
{
y[i+1]=(c[i]*d+ost)%10;
ost=(c[i]*d+ost)/10;
}
y[1]=c[0]*d+ost;
y[0]=dc;
}
}
if(x[0]>y[0])
{
int d=x[0]-y[0],ost=0;
for(i=y[0];i>=1;i--)
{
z[i+d]=(x[i+d]+y[i]+ost)%10;
ost=(x[i+d]+y[i]+ost)/10;
}
for(i=d;i>=1;i--)
{
z[i]=(x[i]+ost)%10;
ost=(x[i]+ost)/10;
}
z[1]=z[1]+ost*10;
z[0]=x[0];
}
else
{
int d=y[0]-x[0],ost=0;
for(i=x[0];i>=1;i--)
{
z[i+d]=(x[i]+y[i+d]+ost)%10;
ost=(x[i]+y[i+d]+ost)/10;
}
for(i=d;i>=1;i--)
{
z[i]=(y[i]+ost)%10;
ost=(y[i]+ost)/10;
}
z[1]=z[1]+ost*10;
z[0]=y[0];
}
for(i=1;i<=z[0];i++)cout<<z[i];
cout<<endl;
}
