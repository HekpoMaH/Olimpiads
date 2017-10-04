#include<iostream>
using namespace std;
int main()
{long a,b,k;
int p;
cin>>a>>b>>k>>p;
int x=0;
while(x!=p+k-1)
{a*=10;if(x>=k-1){cout<<a/b;}a=a%b;
x++;}
cout<<endl;
return 0;}
