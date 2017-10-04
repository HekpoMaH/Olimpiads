#include<iostream>
using namespace std;
long s,n,i,j,x,min1=60001,a[3001],sum;
void qsort(long l,long r)
{
 long i,j,x,y,y1,y2;
 i=l; j=r;
  x=a[(l+r)/2];
   do
   {
    while(a[i]>x) i++;
    while(a[j]<x) j--;
     if(i<=j)
     {
      y=a[i];
      a[i]=a[j];
      a[j]=y;
      i++; j--;
     }
   }while(i<=j);
    if(l<j) qsort(l,j);
    if(r>i) qsort(r,i);
}
main()
{
long br=0;
 cin>>s>>n;
  for(i=1;i<=n;i++)
  cin>>a[i];
     qsort(1,n);
   for(i=1;i<=n;i++)
   {
     sum=a[i];
      br=1;
      for(j=i;j<=n;j++)
      {
	if(sum+a[j]<=s) while(1<2) {if(sum+a[j]<=s) {sum+=a[j];  br++;}else break;}

      }
     if(min1>br) min1=br;
   }
cout<<min1<<endl;
return 0;
}
