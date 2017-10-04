#include<fstream.h>
#include<stdlib.h>
int n,m[10][10],a,b,vis[10],vr,pat[10];
//--------------------------

void vhod()
{ifstream in("way.inp");
in>>n;int k,l,r,br=0;
for(int s=1;s<=n;s++)
{  br+=n-s;}
for(int i=1;i<=br;i++)
{in>>k>>l>>r;
m[k][l]=m[l][k]=r;
}
in>>a>>b;
in.close();
}
//--------------------------
void print()
{ofstream out("way.out");

for(int j=1;j<=n;j++)
out<<pat[j]<<" ";
exit(0);
out.close();
}
//--------------------------
//void depth(int a)//{ vis[a]=1;//for(int i=1;i<=n;i++)//!?
//if(m[a][i]&&(!vis[i])) depth(i);//vr++;//}
//--------------------------
void path(int a)
{ if(a==b&&m[a][b]) print();
else vis[a]=1;
for(int i=1;i<n;i++)
if(m[a][i]&&(!vis[i])) path(i);
}
//--------------------------
void main()
{vhod();
path(a);
ofstream out("way.out");
out<<"0\n";
out.close();
}