#include<iostream>
using namespace std;
int main()
{int n,m,min=9,i;
cin>>n;
for(i=1;i<=n;i++)
{
    cin>>m;
    if(min>m)min=m;
}
cout<<min*n;
return 0;
}
