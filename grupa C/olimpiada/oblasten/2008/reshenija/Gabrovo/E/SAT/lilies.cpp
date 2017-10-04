#include<iostream>
using namespace std;
int main()
{int min,n,s,a,b,c,d,e,f,g,h,i;
cin>>n;
d=0;
min=100;
for(a=1;a<=n;a++)
{cin>>b;
if(min>b)min=b;
d=d+b;
}
d=d-min+1;
cout<<d<<endl;











}
