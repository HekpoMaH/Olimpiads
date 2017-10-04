#include<iostream>
#include<algorithm>
using namespace std;
int a[500005],n;
int main()
{
     cin>>n;
     for(int i=1;i<=n;i++)
     {
         cin>>a[i];
     }
     sort(a+1,a+n+1);
     int br=1,mbr=0,val;
     /*for(int i=1;i<=n;i++)
     {
         cout<<a[i]<<" ";
     }cout<<endl;*/
     a[0]=-1;
     for(int i=1;i<=n;i++)
     {
         
         if(a[i]==a[i-1]) br++;
         if(a[i]!=a[i-1]||i==n)
         {
             if(br>mbr)mbr=br,val=a[i-1];
             br=1;
         }
         //cout<<i<<" "<<br<<" "<<val<<endl;
     }
     if(val==-1)val=a[1];
     cout<<val<<endl;
     return 0;
}