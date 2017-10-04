#include<iostream>
#include<cmath>
using namespace std;
int m;
int long long a,b,k,p;

int main()
{cin>>a>>b;
cin>>k>>p;
 double long long x=1.0*a/b;

 do{x=x*10;
k--;}
while(k!=1);

double long long n=x-floor(x);

do
{int d=n*10;
cout<<d;
n=n*10-d;
p--;}
while(p>0);
cout<<endl;

return 0;
}

