#include<iostream>
using namespace std;
int a[1000],s,n,minbr=9999,b[100],t;
int main()
{ cin>>s>>n;
//запазваме стойностите на марките
for(int i=0;i<n;i++)
cin>>a[i];
//сортираме масива
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
if(a[i]>a[j])
do{t=a[i];
a[i]=a[j];
a[j]=t;}
while(a[i]>a[j]);
int br=1;int k=0;
 br=1;
    while(s/a[k]==0)k++;
do{
   s=s-(br*a[k]);
   br++;
}
while(br*a[k]<s );



cout<<br;
return 0;
}
