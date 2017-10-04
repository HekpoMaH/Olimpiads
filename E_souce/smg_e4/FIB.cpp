#include<iostream>
using namespace std;
int main()
{ {   int n,a,br,b,r;
br=1;
cin>>n;
a=1;
b=0;
while(br<=n)
{ br=br+1;
 b=a+b;
 if(b<=2) r=b;

r=r+a;
 if (b>2) a=r;}
 cout<<b<<endl;
 return 0;
}
