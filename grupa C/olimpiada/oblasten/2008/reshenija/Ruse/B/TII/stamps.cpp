#include<iostream>
using namespace std;
void selsort(int *x, int n)
{int i, j, k; int minx;
  for(i=0; i<n-1; i++)
       {k=i;
         for(j=i+1; j<n; j++) if(x[j]<x[k]) k=j;
         if(k>i) {minx=x[k]; x[k]=x[i]; x[i]=minx;}}}
int main()
{int s,n,i,max;
cin>>s>>n;
int a[n];
for(i=0;i<n;i++)
cin>>a[i];
selsort(a,n);
max=s/a[n-1];
if(max*a[n-1]==s)cout<<max;
return 0;}
