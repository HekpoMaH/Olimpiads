#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
   int s,n,a[111],i,br=0;
   cin>>s;
   cin>>n;
   for(i=1;i<=n;i++)
   {
      cin>>a[i];
   }
   sort(a+1,a+n+1);
   br=br+s/a[n];
   s=s%a[n];
   for(i=n-1;i>=1;i--)
   {
      br=br+s/a[i];
      s=s%a[n];
   }
   cout<<br<<endl;
   return 0;
}