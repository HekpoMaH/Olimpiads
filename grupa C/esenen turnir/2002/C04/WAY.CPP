//Alexander  Rousenov Alexiev Shumen 8kl.
#include<iostream.h>
#include<stdlib.h>
 int n,A,B,a[1000],b[1000],c[1000],d[1000],e[1000];int br=2; int y;
void read()
{
cin>>n;
//while(n!=0)
for(int i=0;i<;i++)
{cin>>a[i]>>b[i]>>c[i]; }
cin>>A>>B;
}
void path()
{ int x;
for(int i=0;i<1000;i++)
{if(a[i]==A && b[i]==B)  x=c[i];
if(x==1)
cout<<1<<endl;
cout<<A<<B<<endl;
exit(0);
}

{ for( i=0;i<1000;i++)
if(a[i]==A && c[i]==1) d[i]=b[i];
	}
for( i=0;i<1000;i++)
if(d[i]==B){ e[i++]=d[i];br++;
y=1;
}
else
for(int i=0;i<1000;i++)
if(d[i]==b[i] && c[i]==1)
if(a[i]==B)
{
y=1;
}
for(i=0;i<1000;i++)
if(d[i]==a[i] && c[i]==1)
if(b[i]==B)
{ y=1;}
}


void main()
{
 read();
 path();
  for(int i=0;i<1000;i++)
  if(y==1) cout<<br<<e[i]<<endl;
}












