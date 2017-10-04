#include<iostream>
using namespace std;
int main ()
{unsigned long long i,a=1,b=1,n,sb=0;
cin>>n;
for(i=1;i<=n;i++)
{a=b;
b=sb;
sb=a+b;
}
cout<<sb;
cout<<endl;
return 0;
}
