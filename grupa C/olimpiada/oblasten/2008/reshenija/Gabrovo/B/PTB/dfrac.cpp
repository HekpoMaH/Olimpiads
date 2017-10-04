#include <iostream>
using namespace std;

int main()
{int p,i=0,j,x,y,a1[100000];
long int a,b;
long long int k;
cin>>a>>b;
cin>>k>>p;

for(;i<=k+p || i<=100000;)
{x=a/b;
a=a-x*b;
if(a<b) a=10*a;
a1[i]=x; i++;
}
for(j=k;j<p+k;j++)
cout<<a1[j];
}
