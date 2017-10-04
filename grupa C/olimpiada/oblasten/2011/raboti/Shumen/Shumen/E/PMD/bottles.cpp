#include<iostream>
using namespace std;
int main ()
{
long long int m,n,sum,c=1,i=0;
cin>>m>>n;
do
{
i++;
sum=i*m+i*n;
if((sum%m==0)&&(sum%n==0)){cout<<i*2<<endl;return 0;}
}
while(c);
}