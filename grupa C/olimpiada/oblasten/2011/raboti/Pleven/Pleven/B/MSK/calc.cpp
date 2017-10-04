#include<iostream>
using namespace std;
int n,s,br,i,j,x,a[1000000];
int main()
{
 cin>>s>>n;
 if(n*s<=10000000)
 {
  for(i=1;i<=n;i++)
   a[i]=1;
  for(i=n+1;i<=s;i++)
  {
   a[i]=1000001;
   for(j=1;j<=n;j++)
   {
    a[i]=min(a[i],a[i/j]+a[i%j]+1);
    a[i]=min(a[i],a[i-j]+1);
   }
  }
  cout<<a[s]<<endl;
 }
 else
 {
  x=s;
  if(n==1) br=s;
  else
   while(1)
   {
    if(x<=n) break;
    if(x%n!=0) br++;
    if(x/n<=n) br++;
    x/=n;
    br++;
   }
  cout<<br<<endl;
 }
 return 0;
}
