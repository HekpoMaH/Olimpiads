/*
TASK:metro
LANG:C++
*/
#include<iostream>
using namespace std;
int a[1001],n;
int main()
{
int i,j,s=0,m1=111,mn=0;
cin>>n;
for(i=1;i<=n;i++)
{
 cin>>a[i];
 s=s+a[i];        
 if(a[i]>mn)
  mn=a[i];
 if(a[i]<m1)
  m1=a[i];        
}
s=(m1+mn)/2;
int br=0;
for(i=1;i<=n;i++)
{
 //cout<<s<<' ';                
if(s<a[i])
 br=br+(a[i]-s)*(a[i]-s);
else
 if(a[i]==s)
  br++;
 else
  br=br+7*(s-a[i]);
if(a[i+1]>s)
 s++;
else
 if(a[i+1]+1<s)
  s=s-2;
 //cout<<br<<endl;      
}
cout<<br<<endl;
//system("pause");
return 0;
}
