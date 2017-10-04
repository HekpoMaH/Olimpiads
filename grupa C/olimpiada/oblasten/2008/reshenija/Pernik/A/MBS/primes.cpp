#include<iostream>
using namespace std;
main()
{
      long int n,c,p;
      long int b;
      long sum[b];
      cin>>n;
      if (n>50000) return 1;
      b=(n-(n%2))/2;
      cout<<b;
      for(long int i=2,p=n+1;i<=p;i++)
      {
         c=p%i;
         if (c==0&&i<p) {p++;}
         if (c==0&&i==p) i=p+1;
         cout<<p<<i;
      }
      system("pause");
      return 0;
}
