#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int y[11],r1[56],r2[56],m[56],k;
bool rec(int c,int i,int ost)
{
int j;
if(c==k)
{
if(!ost && y[0])
{
y[0]--;
r1[c]=0;
return 1;
}
for(j=i;j<=m[0];j++)if(m[j]%3==ost%3)
{
r1[k]=m[j];
return 1;
}
return 0;
}
if(y[0] && c>1)
{
y[0]--;
r1[c]=0;
if(rec(c+1,i,ost))return 1;
y[0]++;
}
for(j=i;j<=m[0];j++)
{
r1[c]=m[j];
if(rec(c+1,j+1,(3+ost%3-m[j]%3)%3))return 1;
}
return 0;
}
bool rec2(int c,int i,int ost)
{
int j;
if(c==k)
{
for(j=i;j>=1;j--)if(m[j]%3==ost%3)
{
r2[k]=m[j];
return 1;
}
if(!ost && y[0])
{
y[0]--;
r2[c]=0;
return 1;
}
return 0;
}
for(j=i;j>=1;j--)
{
r2[c]=m[j];
if(rec2(c+1,j-1,(3+ost%3-m[j]%3)%3))return 1;
}
if(y[0] && c>1)
{
y[0]--;
r2[c]=0;
if(rec2(c+1,i,ost))return 1;
y[0]++;
}
return 0;
}
int main()
{
string s;
cin>>s>>k;
m[0]=s.size();
int i;
for(i=0;i<m[0];i++)m[i+1]=(int)s[i]-48;
int j=1,jj;
for(i=1;i<=m[0];i++)y[m[i]]++;
int l=y[0];
for(i=1;i<=9;i++)
{
for(jj=j;jj<=j-1+y[i];jj++)m[jj]=i;
j=j+y[i];
}
if(!rec(1,1,0))cout<<-1<<endl;
else
{
for(i=1;i<=k;i++)cout<<r1[i];
cout<<' ';
y[0]=l;
rec2(1,m[0],0);
for(i=1;i<=k;i++)cout<<r2[i];
}
}
