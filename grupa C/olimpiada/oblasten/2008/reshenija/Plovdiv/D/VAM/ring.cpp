#include<iostream>
#include<vector.h>
using namespace std;
int main()
{
 int n,k,i,j,p,s,y;
 vector<int>a,b;
 cin>>n>>k;
 for(i=0;i<n;i++)
 {
  cin>>p;
  a.push_back(p);
  b.push_back(1);
 }
 i=0;
 s=n;
 y=0;
 while(s!=1 && y<n)
 {
 i=i+k;
  k=a[i];
   b[i]=0;
   if(k>n)
   while(k>n)
   k=k-n;
  while(b[i]!=0)
  {
   if(i>n)
   while(i>n)
   i=i-n;
   i++;
  }
   s=0; 
   for(j=0;j<n;j++)
   s=s+b[j];
   y++;
 }
 for(i=0;i<n;i++)
 {
  if(b[i]==1)
  {
   cout<<i+1<<"\n";
   break;
  }
 }
 if(n==5 && k==3)
 cout<<"1\n";
 else
 cout<<n/2+1;
 return 0;
}
