#include<iostream>
using namespace std;
long n,s,br,a[1000000];
int main()
 {
   cin>>s>>n;

   br=s/n;
   if(s%n!=0) br++;
   for(int i=1;i<=s;i++)
    for(int j=1;j<=n;j++)
     {
       if(i<=n) a[i]=1;
       if(j<=n) a[j]=1;
       if(j*i<=s)
        if(a[i*j]==0) a[i*j]=a[i]+a[j];
        else a[i*j]=min(a[i*j],a[i]+a[j]);
       if(j+i<=s)
        if(a[i+j]==0) a[i+j]=a[i]+a[j];
        else a[i+j]=min(a[i+j],a[i]+a[j]);
       else break;
     }

   cout<<a[s]<<endl;
   return 0;
 }