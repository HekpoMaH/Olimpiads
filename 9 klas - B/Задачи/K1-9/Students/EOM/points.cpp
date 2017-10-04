#include<iostream.h>
unsigned long long n,k,a[303],h,sum;
int main()
{ long i,j;
  cin>>n>>k;
  a[1]=1;
  for(i=2;i<=n;i++)
  { if (i-k<0) h=0;
    else h=i-k;
    sum=0;
    for(j=h;j<=i-1;j++) sum+=a[j];
    a[i]=sum;
  }
  cout<<a[n]<<endl;
return 0;
}
