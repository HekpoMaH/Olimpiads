#include<iostream>
using namespace std;
int rqz[10001],n,dr[10001],minb;
int v[10001];
int pal(int a, int b)
{
int i;
for(i=a;i<=(a+b)/2;i++)
 if(v[i]!=v[b+a-i])
  return 0;
return 1;
}

int f(int l, int d, int r)
{    
int i;
if(r>=minb)
 return 0;
//cout<<l<<' '<<d<<' '<<dr[r]<<' '<<r<<endl;
if(pal(l,d))
{
if(r<minb)
{
minb=r;
for(i=1;i<=minb;i++)
 rqz[i]=dr[i];
}
}
else
for(i=l;i<d;i++)
 if(pal(l,i))
 {
  dr[r+1]=i;
  //cout<<dr[r+1]<<' '<<r+1<<endl;
  f(i+1,d,r+1);
 }
 return 0; 
}

int main()
{
int i,j,k,l;
cin>>n;
for(i=1;i<=n;i++)
 cin>>v[i];
//scanf  
minb=n+5;
//r=0;
f(1,n,0);
cout<<minb+1<<endl;
for(i=1;i<minb;i++)
cout<<rqz[i]<<' ';
if(minb>0)
cout<<rqz[minb]<<endl;
//cout<<pal(8,16);
return 0;
}
