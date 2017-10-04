#include<iostream>
using namespace std;
int main()
{
long long V,K,N,i,pom;
char a[52];
i=0;
cin>>V;
cin>>K;
cin>>N;
pom = 0;
for(i = 0;i<=N * 2;i++)
{
cin.get(a[i]);
if(a[i] = '-')
pom = pom - K;
else
pom = pom + K;
}
cout<<V<<endl;
return 0;
}
