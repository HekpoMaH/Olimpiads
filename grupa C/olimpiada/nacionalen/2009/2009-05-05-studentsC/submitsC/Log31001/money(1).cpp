/*
TASK:money
LANG:C++
*/
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[300000];
struct dp 
{
       int br;
       int poz;
};
dp dpp[300000];
void read ()
{
     cin>>n;
     int i;
     for(i=0;i<n;i++)cin>>a[i];
}
void solve ()
{
     int i,j,max=0;
     for(i=0;i<n;i++)
     {
                    if(i==0) dpp[i].br=2;
                    else dpp[i].br=dpp[i-1].br-1;
                     if (i==0) dpp[i].poz=2;
                     else dpp[i].poz=dpp[i-1].poz;
                     if(dpp[i].poz==i+1)dpp[i].poz=i+2;
                     j=dpp[i].poz;
                     while(j<n)
                     {
                             if(a[i]+a[i+1]>a[j])
                             {
                                 j++;
                                 dpp[i].br++;}
                             else
                             {
                                 dpp[i].poz=j;
                                 break;
                                 
                             }
                     }
                     dpp[i].poz=j;
                     if(dpp[i].br>max)max=dpp[i].br;
                     if(j==n)break;
     }
     if(max==2)cout<<1<<endl;
     else cout<<max<<endl;
}
void print ()
{
     int i,j;
     for(i=0;i<n;i++)cout<<dpp[i].br<<' '<<dpp[i].poz<<endl;
}
int main ()
{
    read ();
    sort(a,a+n);
    solve ();
    //print ();
}
