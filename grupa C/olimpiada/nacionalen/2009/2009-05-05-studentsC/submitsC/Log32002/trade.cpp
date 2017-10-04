/*
TASK:trade
LANG:c++
*/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,l=0;
double w[200000],q[200000];
struct edge
{
       int f;
       double fs;
       int s;
       double ss;
       };
       edge a[200000];
void read ()
{
     cin>>n;
     int i,x,y;
     double z;
     for(i=1;i<=n;i++)
     {
                      cin>>x>>y>>z;
                      if(z==0)l=1;
                      if(a[x].f==0){a[x].f=y;a[x].fs=z;}
                      else {a[x].s=y;a[x].fs=z;}
                      if(a[y].f==0){a[y].f=x;a[y].fs=z;}
                      else {a[y].s=x;a[y].fs=z;}
                      
     }
} 
void solve()
{
     int i;
     double dd;
     cout<<"impossible"<<endl;return;
     i=a[1].f;
     dd=a[i].fs;
     while(1)
     {
             if(a[i].s==1||a[i].f==1)break;
             else
             {
                if(a[i].s!=i){dd=a[i].ss-dd;i=a[i].s;}
                else {dd=a[i].fs-dd;i=a[i].f;} 
             }
     }
     w[1]=(a[1].ss-dd)/2;
     printf("%.2lf",w[1]);
}
int main ()
{
    read ();
    solve();
}
