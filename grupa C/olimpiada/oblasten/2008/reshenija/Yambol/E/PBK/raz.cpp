#include<iostream>
using namespace std;
int main()
{    
long long N,min,min1,min2,b,i,k;
char a[52];
cin>>N;
min=12345;
min1=0;
min2=0;
for(i=1;i<=N;i++)
{
k=N/i;
if(k>i)
b=k-i;
else
b=i-k;
if(N%i==0)
if(b<min)
{
min=b;
min1=k;
min2=i;
}
}
if(min1>min2)
cout<<min2<<" "<<min1<<endl;
else
cout<<min1<<" "<<min2<<endl;
return 0;
}
