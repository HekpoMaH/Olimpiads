#include<iostream>
using namespace std;
long b[5555],n,s,i,j,a[3333],min1;
int main()
{

   cin>>s>>n;
  for(i=1;i<=n;i++)
    cin>>a[i];
    min1=a[1];
  for(i=2;i<=n;i++)
    if(a[i]<min1) min1=a[i];
  for(i=0;i<=s-min1;i++)
      for(j=1;j<=n;j++)
       {   
          if(b[a[j]+i]!=0 && b[a[j]+i]>b[i]+1) b[a[j]+i]=b[i]+1;
          else if(b[a[j]+i]==0) b[a[j]+i]=b[i]+1;
        }
 cout<<b[s];
   cout<<endl; 
  return 0;
}
