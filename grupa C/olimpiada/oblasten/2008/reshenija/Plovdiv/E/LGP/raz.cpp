#include<iostream>
using namespace std;
int main ()
{unsigned long long min=1000000,i,n,mn,mn2;
cin>>n;
for(i=1;i<=n;i++)  
{if(n%i==0)
{                   
if(min>((n/i)-i))
{
min=((n/i)-i);
mn=i;
mn2=n/i;
}}}
cout<<mn<<" "<<mn2<<endl;
return 0;
}
