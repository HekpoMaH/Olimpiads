#include<iostream>
using namespace std;
int main()
{int v,k,n,i;
char j;
cin>>v;
cin>>k;
cin>>n;
for(i=1;i<=n;i++)
{
    cin>>j;
    if(j=='+')v=v+k;
    if(j=='-')v=v-k;
}
cout<<v;
return 0;
}
