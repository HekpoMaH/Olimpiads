/*
TASK:money
LANG:C++
*/
#include<iostream>
using namespace std;
int a[1000001];
int dvt(int k,int l,int d)
{
 if(k<a[l])
  return l-1;
 if(k>a[d])
  return d;    
 if(k>a[(l+d)/2+1])
  return dvt(k,(l+d)/2+1,d);  
 if(k<=a[(l+d)/2])
  return dvt(k,l,(l+d)/2-1);
 return (l+d)/2;
}
int main()
{
int n,i,j;
cin>>n;
for(i=1;i<=n;i++)
 scanf("%d",&a[i]);
sort(a+1,a+n+1);
 int m=0;
for(i=1;i<=n-2;i++)
{
 j=dvt(a[i]+a[i+1],1,n); 
 if(m<j-i+1)
  m=j-i+1;                
}
if(m<3)
 m=1;
cout<<m<<endl; 
//system("pause");
return 0;
}
