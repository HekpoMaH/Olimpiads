#include <iostream>
#include <algorithm>
using namespace std;

int main()
{int s,n,a[3001],p,i,j,br=0;
cin>>s>>n;
for(i=1;i<=n;i++)
cin>>a[i];
sort(a,a+n+1);

for(j=n;j>=1;j--)
{if(s%a[j]==0) {br=br+s/a[j]; break;}
else
{p=s/a[j];
s=s-p*a[j];
br=br+p;}
}
cout<<br+1;
}
