#include<iostream>
using namespace std;
int a[1501][1501];
int main()
{
int n,k,i,j,l,p,r,s,maxmax=-500001,br;
cin>>n>>k;
for(i=1;i<=n+k;i++)
 for(j=1;j<=n+k;j++)
  a[i][j]=0;
for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
  cin>>a[i][j];
  
for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
  {
        
   br=a[i][j];
   for(l=i+1;l<=i+k;l++)
    br=br+a[l][j];
   for(p=j+1;p<=j+k;p++)
    br=br+a[i][p]; 
   if(br>maxmax)
    {
     maxmax=br;
     r=i;
     s=j;   
    }       
  }
cout<<r<<" "<<s<<endl;   
return 0;
}
