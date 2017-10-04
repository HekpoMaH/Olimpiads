#include<iostream>
using namespace std;
long long s1,max1,s,j1,i1,a[10000][10000],k,i,j,m,n,b[10000][10000],x,y;       
int main()
{
cin>>m>>n>>k;
for(i=1;i<=m;i++)
{for(j=1;j<=n;j++)
{cin>>a[i][j];s1+=a[i][j]; }}

for(i=1;i<=m;i++)
{
  for(j=1;j<=n;j++)
   {
    for(i1=i;i1<=i+k-1;i1++)
     {
        for(j1=j;j1<=j+k-1;j1++)
         {
             s+=a[i1][j1];                  
         }
     }
     
b[i][j]=s; s=0;    }
}
for(i=1;i<=m;i++)
{
  for(j=1;j<=n;j++)
   {if(b[i][j]>max1){max1=b[i][j];x=i;y=j;}}}
   cout<<s1-max1<<endl;
    
    return 0;
}
